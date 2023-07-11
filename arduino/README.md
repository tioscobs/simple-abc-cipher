# Simple ABC Cipher - Arduino version

The arduino version of the ABC cipher.
> Added PT-BR translated project for educational purposes

## Components needed (feel free to change!)

* Arduino UNO
* 4 Buttons
* 3 LED's
* 8 1mΩ Resistors
* A lot of cables
* Potentiometer

## Example Circuit

![](https://github.com/tioscobs/simple-abc-cipher/blob/main/arduino/example/circuit2.png)

## Encoded-characters Table
| Frequency   | Characters       | Output |
| :---------- | :--------- | :-------- |
| `0` | 'A' | A |
| `0` | 'B' | B |
| `0` | 'C' | C |
| `0` | 'AB' | D |
| `0` | 'AC' | E |
| `0` | 'BA' | F |
| `0` | 'BC' | G |
| `0` | 'CA' | H |
| `0` | 'CB' | I |
| `1` | 'A' | J |
| `1` | 'B' | K |
| `1` | 'C' | L |
| `1` | 'AB' | M |
| `1` | 'AC' | N |
| `1` | 'BA' | O |
| `1` | 'BC' | P |
| `1` | 'CA' | Q |
| `1` | 'CB' | R |
| `2` | 'A' | S |
| `2` | 'B' | T |
| `2` | 'C' | U |
| `2` | 'AB' | V |
| `2` | 'AC' | W |
| `2` | 'BA' | X |
| `2` | 'BC' | Y |
| `2` | 'CA' | Z |
| `2` | 'CB' | Space |

> *Note:* This table can change at any moment
