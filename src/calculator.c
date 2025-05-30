/*********************************************************************************************************************
Copyright (c) 2025, Soria Martin Nicolas <soria.m.nicolas@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

/** @file calculator.c
 ** @brief Code para la implementación de una calculadora simple
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* === Macros definitions ========================================================================================== */
#ifndef MAX_OPERATIONS
#define MAX_OPERATIONS 16
#endif
/* === Private data type declarations ============================================================================== */


/* Tipo de datos para las operaciones */
typedef struct operation_s *operation_t;
struct operation_s {
    char operator;
    operation_func_t func;
    operation_t next;
};

/* Tipo de datos para la calculadora */
struct calculator_s {
    operation_t operations;
};

/* === Private function declarations =============================================================================== */

/**
 * @brief Busca una operación en la calculadora por su operador.
 *
 * @param calculator Calculadora donde buscar la operación.
 * @param operator Operador de la operación a buscar.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
static operation_t FindOperation(calculator_t calculator, char operator);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */


/**
 * @brief Busca una operación en la calculadora por su operador.
 *
 * @param calculator Calculadora donde buscar la operación.
 * @param operator Operador de la operación a buscar.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
static operation_t FindOperation(calculator_t calculator, char operator) {
    operation_t current = calculator->operations;
    while (current != NULL) {
        if (current->operator == operator) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* === Public function implementation ============================================================================== */


/**
 * @brief Crea una nueva calculadora.
 *
 * @return Un puntero a la nueva calculadora o NULL si falla.
 */
calculator_t calculator_create(void){
    calculator_t self = malloc(sizeof(struct calculator_s));
    if (self) {
        self->operations = NULL;
    }
    return self;
}

/**
 * @brief Agrega una operación a la calculadora.
 *
 * @param calculator Calculadora donde buscar la operación.
 * @param operator Operador de la operación a buscar.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
bool calculator_add_operation(calculator_t calculator, char operator, operation_func_t func) {
    if (!calculator||!func||FindOperation(calculator, operator)) {
        return false;
    }
    operation_t operation = malloc(sizeof(struct operation_s));
    if (operation) {
        operation->operator = operator;
        operation->func = func;
        operation->next = calculator->operations;
        calculator->operations = operation;
        return true;
    }
    return false;
}


/**
 * @brief Busca una operación en la calculadora por su operador.
 *
 * @param calculator Calculadora donde buscar la operación.
 * @param operator Operador de la operación a buscar.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
int calculator_calculate(calculator_t calculator, const char *expression) {
    int a=0, b=0;
    char operator=0;
    int result = 0;
    char *endptr = NULL;

    if (!calculator || !expression) {
        return 0;
    }

    a = (int) strtol(expression, &endptr, 10);
    operator = *endptr;
    if (operator == 0) {
        return 0; 
    }
    b = (int) strtol(endptr + 1, NULL, 10);

    operation_t operation = FindOperation(calculator, operator);
    if (operation) {
        result = operation->func(a, b);
    }
    return result;
}



/**
 * @brief Libera la memoria asignada a la calculadora y sus operaciones.
 *
 * @param calculator Calculadora a destruir.
 */
void calculator_destroy(calculator_t calculator) {
    if (!calculator) return;

    operation_t current = calculator->operations;
    while (current) {
        operation_t next = current->next;
        free(current);
        current = next;
    }

    free(calculator);
}


/**
 * @brief Realiza una operación de suma.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la suma.
 */
int operation_add(int a, int b) {
    return a + b;
}

/**
 * @brief Realiza una operación de resta.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la resta.
 */
int operation_subtract(int a, int b) {
    return a - b;
}

/**
 * @brief Realiza una operación de la multiplicacion.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la multiplicacion.
 */
int operation_multiply(int a, int b) {
    return a * b;
}

/**
 * @brief Realiza una operación de la division.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la division.
 */
int operation_divide(int a, int b) {
    if (b == 0) {
        printf("Error: División por cero\n");
        return 0; 
    }
    return a / b;
}

/* === End of documentation ======================================================================================== */
