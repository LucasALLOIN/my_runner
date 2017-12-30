/*
** EPITECH PROJECT, 2017
** Project my_runner Testing
** File description:
** Unit Testing Project my_runner
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "main.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
}

Test(my_runner, Return_Value_Test)
{
	cr_assert_eq("Function to test()", "Int Output..");
}

Test(my_runner, Stdout_Value_Test, .init = main_redirect_stdout)
{
	cr_assert_stdout_eq_str("Str Output..");
}
