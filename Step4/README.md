# Step4: Installing and Testing

## インストール

MyLibrary のインストールは、ライブラリファイルを lib に、ヘッダファイルを include に配置する。
MyLibrary の CMakeLists.txt に、下記を追加する。

```cmake
install(TARGETS MyLibrary DESTINATION lib)
install(FILES MyMethods.hpp DESTINATION include)
```

また、Tutorial のインストールは、実行ファイルを bin に、ヘッダファイル(コンフィグファイル)を include に配置する。
ルートの CMakeLists.txt に、下記を追加する。

```cmake
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.hpp"
  DESTINATION include
  )
```

インストールを実行するには、下記を実行する。

```cmake
cmake --install .
```

ただし、Visual Studio の C++ コンパイラでビルドする場合は、マルチコンフィギュレーションに対応しているので、`--config` オプションを指定する必要がある。

```cmake
cmake --install . --config Debug
```

Windows の場合は、"C:/Program Files (x86)/Tutorial" 以下に配置されるので、管理者権限が必要である。

インストール先を設定するには、`--prefix` オプションを指定する。

```cmake
cmake --install . --config Debug --prefix ../bin
```

## テスト

`enable_testing()` をしてから、テストを書いていく。

```cmake
enable_testing()

add_test(NAME Runs COMMAND Tutorial 2 10)

add_test(NAME Output COMMAND Tutorial 2 10)
set_tests_properties(Output
  PROPERTIES PASS_REGULAR_EXPRESSION "Hel.*rld!"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(Tutorial 1 2 "1")
do_test(Tutorial 2 2 "4")
do_test(Tutorial 2 5 "32")
do_test(Tutorial 2 10 "1024")
do_test(Tutorial 3 3 "27")
do_test(Tutorial 10 5 "100000")
```

下記の行は、Tutorial コマンドを実行したときに、落ちたりしないか、戻り値が 0 か、をテストする。

```cmake
add_test(NAME Runs COMMAND Tutorial 2 10)
```

下記の行は、Tutorial コマンドを実行したときに、特定の文字列が出力されるかをテストする。
正規表現で "Hel.*rld!" と一致するかを確認している。

```cmake
add_test(NAME Output COMMAND Tutorial 2 10)
set_tests_properties(Output
  PROPERTIES PASS_REGULAR_EXPRESSION "Hel*rld!"
  )
```

最後に `do_test()` を定義して、いくつかのテストを追加している。

実行するには、`ctest` を実行する。
Visual Studio の C++ コンパイラでビルドした場合などは、-C オプションでコンフィギュレーションを指定する。

```cmake
ctest -C Debug
```
