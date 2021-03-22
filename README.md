# Пишем библиотеку для поиска информации в тексте на языке С++ 

Поиск:
1. Последовательный.
2. Алгоритм Кнута-Морриса-Пратта.
3. Алгоритм Бойера-Мура-Хорспула.

## Последовательный поиск

Суть: поэлементное сравнение строк.

Сложность вычислений: **O(nm)**, где n - длина строки, m - длина подстроки.

Реализация на языке С++
```C++
bool SequentialSearching(std::string str, std::string part) {

  if (str.length() < part.length()) {

    return false;
  }
  else {

    for (int i = 0; i < str.length(); i++) {

      bool temp = true;

      for (int j = 0; j < part.length(); j++) {

        if (str[j + i] != part[j]) {

          temp = false;
          j = part.length();
        }
      }

      if (temp) {

        return true;
      }
    }
  }

  return false;
}
```

## Алгоритм Кнута-Морриса-Пратта.

Суть: использование вспомогательного массива с максимальными длинами суффиксов и префиксов к данной подстроке для более быстрого перебора элементов в тексте.

Сложность вычислений: **O(n+m)**, где n - длина строки, m - длина подстроки.

Реализация на языке С++

```C++
void CreatePiArray(std::vector <int>& pi, std::string str) {

  int j = 0, i = 1;

  while (i < str.length()) {

    if (str[i] == str[j]) {

      pi[i] = j + 1;
      i++;
      j++;
    }
    else if (j == 0) {

      pi[i] = 0;
      i++;
    }
    else {

      j = pi[j - 1];
    }
  }
}
```

```C++
bool KnuthMorrisPrattTextSearching(std::string str, std::string part) {

  std::vector <int> pi(str.length());
  CreatePiArray(pi, str);

  int strIndex = 0, partIndex = 0;

  while (strIndex < str.length()) {

    if (str[strIndex] == part[partIndex]) {

      strIndex++;
      partIndex++;

      if (partIndex == part.length()) {

        return true;
      }
    }
    else if (partIndex == 0) {

      strIndex++;

      if (strIndex == str.length()) {

        return false;
      }
    }
    else {

      partIndex = pi[partIndex - 1];
    }
  }
}
```
## Алгоритм Бойера-Мура-Хорспула

Суть алгоритма: смещение искомой строки согласно таблице смещений.

Сложность вычислений (худший случай): **O(nm)**, где n - длина строки, m - длина подстроки.
Сложность вычислений (худший случай): **O(n/m)**, где n - длина строки, m - длина подстроки.

Реализация на языке С++
```C++
bool BoyerMooreTextSearching(std::string str, std::string part) {

  int strLen = str.length();
  int partLen = part.length();

  if (strLen < partLen) {

    return false;
  }

  std::map <char, int> offsetTable;

  for (int i = 0; i <= 255; i++) {

    offsetTable.insert(std::make_pair(static_cast<char>(i), partLen));
  }

  for (int i = 0; i < partLen - 1; i++) {

    offsetTable.insert(std::make_pair(part[i], partLen - i - 1));
  }

  int i = partLen - 1;
  int j = i;
  int k = i;

  while (j >= 0 && i <= partLen - 1) {

    j = partLen - 1;
    k = i;

    while (j >= 0 && str[k] == part[j]) {

      k--;
      j--;
    }

    i += offsetTable[i];
  }

  if (k >= strLen - partLen) {

    return false;
  }
  else {

    return true;
  }
}
```
