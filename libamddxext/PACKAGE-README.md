# libamddxext - AMD Direct3D driver extension C++ API headers

This is a `build2` package for the `AmdDxExt` C++ library maintained in the
[`gpu_performance_api`](https://github.com/GPUOpen-Tools/gpu_performance_api)
repository (`source/third_party/AmdDxExt`). It provides the headers of the
AMD driver extension API for Direct3D, which gives applications and tools
access to functionality of the AMD driver beyond the standard Direct3D 10,
11, and 12 APIs, such as extended primitive topologies, ASIC information,
performance profiling, GPU Performance API (GPA) counters, and command list
markers.


## Usage

To start using `libamddxext` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libamddxext ^4.4.1
```

Then import the library in your `buildfile`:

```
import libs = libamddxext%lib{amddxext}
```


## Importable targets

This package provides the following importable targets:

```
lib{amddxext}
```

The extension headers, included without a subdirectory prefix
(`#include <AmdDxExtApi.h>`, `#include <AmdExtD3D.h>`, and so on). The
package version is the version of the `gpu_performance_api` release the
headers are taken from.

This package is headers only. The extension objects are created at runtime
by the entry points exported by the AMD driver DLLs (`AmdDxExtCreate11()` for
Direct3D 11 and `AmdExtD3DCreateInterface()` for Direct3D 12, loaded with
`GetProcAddress()` using the function pointer types declared in the headers).

As in upstream, the headers target Windows and some of them rely on the
Windows, COM, and Direct3D declarations being already included (for example,
`<d3d11.h>` must be included before `<AmdDxExtApi.h>`). They also use
Microsoft C++ extensions and so require MSVC or Clang targeting MSVC (MinGW
is not supported).


## Configuration variables

This package provides no configuration variables.
