### Конфигурация проекта для сборки

```console
cmake -D CMAKE_BUILD_TYPE=Release \
      -D GLOB_EMSCRIPTEN_PLATFORM=OFF \
      -D MODULE_OIS_ENABLE_EXAMPLES=ON \
      ../
```


### Запуск сборки

```console
cmake --build ./
```
