# Credit Card Validator (C)

This program validates credit card numbers using Luhn’s Algorithm and
identifies the card type (AMEX, MasterCard, Visa).

Built as part of the CS50 Introduction to Computer Science course to
practice loops, conditionals, and integer arithmetic in C.

## How it works
- Counts digits of the card number
- Applies Luhn’s checksum algorithm
- Identifies card type based on prefix and length

## Compile & Run
gcc credit.c -o credit
./credit
