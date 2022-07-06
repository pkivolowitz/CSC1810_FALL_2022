# Integers

## Canonical Types

Note: Keyword `signed` as in `signed int` can be omitted and typically
is.

| Signed | Unsigned | Minimum<br>Width | Common<br>Width |
| ------ | -------- | ---------------- | --------------- |
| char<sup>\*</sup> | unsigned char<sup>*</sup> | 8 | 8 |
| short | unsigned short | 16 | 16 |
| int | unsigned int | 16 | 32 |
| long | unsigned long | 32 | 64 |
| long long | unsigned long long | 64 | 64 |

<sup>*</sup>The language standard leaves it up to the implementers of
a compiler to decide if `char` means signed or unsigned. From
[cppreference](https://en.cppreference.com/w/cpp/language/types):

*The signedness of char depends on the compiler and the target platform:
the defaults for ARM and PowerPC are typically unsigned, the defaults
for x86 and x64 are typically signed.*

The only guarantees made by C++ is that:

1 = sizeof(char) &le; sizeof(short) &le; sizeof(int) &le;
sizeof(long) &le; sizeof(long long)

*I encourage you to use the precise types in your work.*

> *“Then you should say what you mean."<br/> - the March Hare*


## Precise Types

As given in `cstdint` (often provided via `iostream`) the following
are precise aliases for the integer types:

| Signed | Unsigned | Width |
| ------ | -------- | ----- |
| int8_t | uint8_t | 8 |
| int16_t | uint16_t | 16 |
| int32_t | uint32_t | 32 |
| int64_t | uint64_t | 64 |

## `char` is Complicated

The association of `char` with characters leads to even more complexities
which lie outside the scope of CSC 1810. For example, "wide characters"
are larger than 8 bits but still hold "characters".
