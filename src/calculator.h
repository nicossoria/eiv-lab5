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

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/** @file calculator.h
 ** @brief Declaraciones para la calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/*Tipo de datos para el objeto calculadora */
typedef struct calculator_s *calculator_t;

/* Tipo de datos para las operaciones */
typedef int (*operation_func_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Crea una nueva calculadora.
 *
 * @return Un puntero a la nueva calculadora o NULL si falla.
 */
calculator_t calculator_create(void);


/**
 * @brief Agrega una operación a la calculadora.
 *
 * @param calculator Calculadora donde buscar la operación.
 * @param operator Operador de la operación a buscar.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
bool calculator_add_operation(calculator_t calculator, char operator, operation_func_t func);



/**
 * @brief Busca una operación en la calculadora por su operador.
 *
 * @param calculator Calculadora donde buscar la operación.
 * @param operator Operador de la operación a buscar.
 * @return Puntero a la operación encontrada o NULL si no se encuentra.
 */
int calculator_calculate(calculator_t calculator, const char *expression);

/**
 * @brief Libera la memoria asignada a la calculadora y sus operaciones.
 *
 * @param calculator Calculadora a destruir.
 */
void calculator_destroy(calculator_t calculator);

/**
 * @brief Realiza una operación de suma.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la suma.
 */
int operation_add(int a, int b);

/**
 * @brief Realiza una operación de resta.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la resta.
 */
int operation_subtract(int a, int b);

/**
 * @brief Realiza una operación de la multiplicacion.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la multiplicacion.
 */
int operation_multiply(int a, int b);

/**
 * @brief Realiza una operación de la division.
 *
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return Resultado de la division.
 */
int operation_divide(int a, int b);


/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H_ */
