# sway.module_ois [![Discord](https://discordapp.com/api/guilds/402238411639095297/widget.png)](https://discord.gg/vCMcgwQ)

[![codecov][codecov-svg]][codecov-url] [![BCH compliance][bettercodehub-svg]][bettercodehub-url] [![Documentation][codedocs-svg]][codedocs-url] [![License][license-svg]][license-url]

### Клонирование проекта

```console
git clone --recursive https://github.com/timcogames/sway.module_ois.git
```

### Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

```console
cmake -DCMAKE_BUILD_TYPE=Release ../

cmake -DCMAKE_BUILD_TYPE=Release \
      -DGLOB_EMSCRIPTEN_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/emsdk/upstream/emscripten \
      -DGLOB_EMSCRIPTEN_PLATFORM=ON \
      -DMODULE_CORE_ENVIRONMENT=web,node \
      -DMODULE_CORE_COMPILATION=ON \
      -DMODULE_OIS_ENVIRONMENT=web,node \
      -DMODULE_OIS_COMPILATION=ON ../
```

Опция сборки | Описание | По умолчанию
:---|:---|:---:
`BUILD_SHARED_LIBS` | Сборка библиотеки общего пользования | `OFF`

Запускаем сборку

```console
cmake --build .

python3 -m http.server <PORT>
```

[codecov-svg]: https://codecov.io/gh/timcogames/sway.module_ois/branch/master/graph/badge.svg
[codecov-url]: https://codecov.io/gh/timcogames/sway.module_ois
[bettercodehub-svg]: https://bettercodehub.com/edge/badge/timcogames/sway.module_ois?branch=master
[bettercodehub-url]: https://bettercodehub.com/
[codedocs-svg]: https://codedocs.xyz/timcogames/sway.module_ois.svg
[codedocs-url]: https://codedocs.xyz/timcogames/sway.module_ois/
[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE
