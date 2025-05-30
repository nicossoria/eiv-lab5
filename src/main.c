/*********************************************************************************************************************
Copyright (c) Año, Nombre y Apellido del autor <correo@ejemplo.com>

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

/** @file main.c
 ** @brief Main file para una calculadora simple
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */

int main(void) {
    static const char suma[] = "2+3";
    static const char producto[] = "2*3";
    static const char resta[] = "3-2";
    static const char division[] = "6/3";

    calculator_t calculator = calculator_create();
    calculator_add_operation(calculator, '+', operation_add);
    calculator_add_operation(calculator, '*', operation_multiply);
    calculator_add_operation(calculator, '-', operation_subtract);
    calculator_add_operation(calculator, '/', operation_divide);

    printf("%s= %d\n", suma, calculator_calculate(calculator, suma));
    printf("%s= %d\n", producto, calculator_calculate(calculator, producto));
    printf("%s= %d\n", division, calculator_calculate(calculator, division));
    printf("%s= %d\n", resta, calculator_calculate(calculator, resta));

    calculator_destroy(calculator);
}

/* === End of documentation ======================================================================================== */
