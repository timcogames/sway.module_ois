# sway.module_ois-x11 [![Discord](https://discordapp.com/api/guilds/402238411639095297/widget.png)](https://discord.gg/vCMcgwQ)

[![Build Status][travis-svg]][travis-url] [![codecov][codecov-svg]][codecov-url] [![BCH compliance][bettercodehub-svg]][bettercodehub-url] [![Documentation][codedocs-svg]][codedocs-url] [![License][license-svg]][license-url]

### Клонирование проекта

```console
git clone --recursive https://github.com/timcogames/sway.module_ois-x11.git
```

### Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

```console
cmake -DCMAKE_BUILD_TYPE=Release ../
```

Опция сборки | Описание | По умолчанию
:---|:---|:---:
`BUILD_SHARED_LIBS` | Сборка библиотеки общего пользования | `OFF`

Запускаем сборку

```console
cmake --build .
```

[travis-svg]: https://travis-ci.org/timcogames/sway.module_ois-x11.svg?branch=master
[travis-url]: https://travis-ci.org/timcogames/sway.module_ois-x11
[codecov-svg]: https://codecov.io/gh/timcogames/sway.module_ois-x11/branch/master/graph/badge.svg
[codecov-url]: https://codecov.io/gh/timcogames/sway.module_ois-x11
[bettercodehub-svg]: https://bettercodehub.com/edge/badge/timcogames/sway.module_ois-x11?branch=master
[bettercodehub-url]: https://bettercodehub.com/
[codedocs-svg]: https://codedocs.xyz/timcogames/sway.module_ois-x11.svg
[codedocs-url]: https://codedocs.xyz/timcogames/sway.module_ois-x11/
[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE
