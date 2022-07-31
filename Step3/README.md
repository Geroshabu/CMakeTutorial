# Step3: Adding Usage Requirements for a Library

前回作った MyLibrary 内にあるヘッダファイルは、MyLibrary をリンクする側にとっては必要となるが、MyLibrary 自身には必要ない。

そういうときには、MyLibrary の CMakeLists.txt に、下記を追加する。
`INTERFACE` は、自身には必要ではないが、その使用者にとって必要な場合に指定する。

```cmake
target_include_directories(MyLibrary
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
```

こうすることにより、ルートの CMakeLists.txt から、変数 `EXTRA_INCLUDES` に関する処理を取り除くことができる。

