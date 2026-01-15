# Credit Card Validator (C)

This program validates credit card numbers using Luhn’s Algorithm and
identifies the card type (AMEX, MasterCard, Visa).

## How it works
- Counts digits of the card number
- Applies Luhn’s checksum algorithm
- Identifies card type based on prefix and length

## Compile & Run
gcc credit.c -o credit
./credit
