https://github.com/pando-project/jerryscript/issues/1884

disable js-parser, jerry-ext, jerry-libm, jerry-libc, jerry-port-default, use the minimal profile , use the build option Os,
This is interesting, because from my build, the minimal.profile really helped a lot, while abandon js-parser doesn't.
with minimal profile. the size is like the following:
bare-HAL: 24k
bare-HAL + jerry-vm = 67k
bare-HAL + jerry-vm + js-parser = 91k

```
include(CMakeForceCompiler)
set(CMAKE_SYSTEM_NAME MCU)
set(CMAKE_SYSTEM_PROCESSOR armv7l)
set(CMAKE_SYSTEM_VERSION STM32F1)
set(FLAGS_COMMON_ARCH -mlittle-endian -mthumb -mcpu=cortex-m3 -march=armv7-m)
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
```

with jerry-vm+es5.1profile, it's 150k
with jerry-vm+js-parser+es5.1profile, it's 170k
