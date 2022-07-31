# Step1: A Basic Starting Point

## 基本

動作させるためにC++コンパイラが必要になる。
gccや、Visual StudioでC++コンパイラをインストールしておくこと。

CMakeLists.txt が必要。
ビルドに最低限必要な記述は下記の3行。

```cmake
cmake_minimum_required(VERSION 3.10)
project(Tutorial)
add_executable(Tutorial tutorial.cxx)
```

```
mkdir build
cd build
cmake ../
```

で、コンパイラに合ったビルド設定(.slnやMakefile)を作成し、

```
cmake --build .
```

でビルド。
