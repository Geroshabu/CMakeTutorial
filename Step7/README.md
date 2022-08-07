# Step 7: Packaging an Installer

Step4で、ビルド成果物を特定のフォルダに配置するようにした。

例えば、下記のように記載したとする。

./CMakeLists.txt:
```cmake
install(TARGETS Tutorial DESTINATION bin)
```
./MyLibrary/CMakeLists.txt:
```cmake
install(TARGETS MyMath DESTINATION lib)
install(FILES math.hpp DESTINATION include)
```

ビルド成果物は、下記のように配置される。

```
インストールディレクトリ
  + bin
  |   + Tutorial.exe
  + include
  |   + math.hpp
  + lib
      + MyMath.lib
```

ここまでは、cmake を実行したマシンで実施する。
これら成果物を、別のマシンにもっていって実行するためには、インストーラを作成したり、アーカイブファイルを作成するなどが必要である。
その方法を、このステップで実施する。

そのためには、下記の行をトップの CMakeLists.txt の末尾に追加する。

```cmake
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "ZIP")
include(CPack)
```

`InstallRequiredSystemLibraries` をインクルードすると、その環境に合ったランタイムライブラリが、実行ディレクトリに用意される。

`CPACK_RESOURCE_FILE_LICENSE` に指定したファイルは、ライセンスファイルとしてインストーラに組み込まれる。
ただし、NSISなどのインストーラ作成ツールの場合のみ組み込まれ、ZIPで固めるだけの場合などは、無視される。
(NSIS: GUI を持ったインストーラーを作成できる。)

`CPACK_PACKAGE_VERSION_MAJOR` 等に指定する、バージョン番号の定数 (`Tutorial_VERSION_MAJOR` 等) は、Step1で設定したとおりである。

`CPACK_SOURCE_GENERATOR` は、ソースファイルを提供する場合に、そのパッケージ方法を指定する。

実行するには、下記コマンドを実行する。

```
cpack
```

ただし、オプション無指定だと、NSIS を用いてインストーラを作成しようとする。
NSIS がインストールされていない環境だと、失敗する。
パッケージ方法を指定するには、`-G` オプションを指定する。

また、MSVC などマルチコンフィギュレーション対応のコンパイラを使う場合は、`-C` オプションでコンフィギュレーションを指定する。

```
cpack -G ZIP -C Debug
```

このようにすると、ビルド成果物がパッケージされる。

また、ソースコードも含めて丸ごとアーカイブしたい場合、下記のようにする。

```
cpack --config CPackSourceConfig.cmake
```
