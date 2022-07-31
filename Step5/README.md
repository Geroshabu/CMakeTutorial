# Step5: Adding System Introspection

特定の関数が使用可能な環境なのかは、次のように調べることができる。
次の例では、pow関数を使用できるかを調べている。

```cmake
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
  #include <cmath>
  int main() {
    std::pow(2, 10);
    return 0;
  }
" HAVE_POW)
```

`check_cxx_source_compiles` は、試しにコードを実行してみて、成功すればその関数を使える環境にあると判断してくれる。
使用するには、`CheckCXXSourceCompiles` モジュールをインクルードする必要がある。

もし使用可能なら、コンパイル時、MyLibrary 内で `HAVE_POW` という定数が定義されるようにする。

```cmake
if(HAVE_POW)
  target_compile_definitions(MyLibrary
                             PRIVATE "HAVE_POW")
endif()
```

あとは、ソースコード内で、`HAVE_POW` を使って場合分けをする。

```cpp
#if defined(HAVE_POW))
    double ret = std::pow(x, y);
    std::cout << "Using std::pow" << std::endl;
#else
    int ret = 1;
    for (int i = 0; i < y; i++){
        ret *= x;
    }
#endif
```

これで、`std::pow` が使える環境であれば使うし、使えない環境であれば使わないというプログラムを作成できる。
