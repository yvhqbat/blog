
```
[static] QString QString::number(long n, int base = 10)
```
Returns a string equivalent of the number n according to the specified base.
The base is 10 by default and must be between 2 and 36. For bases other than 10, n is treated as an unsigned integer.
The formatting always uses QLocale::C, i.e., English/UnitedStates. To get a localized string representation of a number, use QLocale::toString() with the appropriate locale.
```
  long a = 63;
  QString s = QString::number(a, 16);  // s == "3f"
  QString t = QString::number(a, 16).toUpper();  // t == "3F"
```
