# GPUOpen-gpu_performance_api - AMD GPU Performance API (GPUPerfAPI)

This is a `build2` package repository for
[`gpu_performance_api`](https://github.com/GPUOpen-Tools/gpu_performance_api),
the AMD GPU Performance API (GPUPerfAPI, or GPA) library which provides access
to GPU performance counters of AMD Radeon GPUs. It also contains the AMD
Direct3D driver extension API headers that GPUPerfAPI maintains in
`source/third_party/AmdDxExt`.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libgpuperfapi-headers` (the GPUPerfAPI headers) or `libamddxext` (the
Direct3D driver extension headers) in your `build2`-based project, then
instead see the accompanying
[`libgpuperfapi-headers/PACKAGE-README.md`](libgpuperfapi-headers/PACKAGE-README.md)
and [`libamddxext/PACKAGE-README.md`](libamddxext/PACKAGE-README.md) files.

The development setup for `GPUOpen-gpu_performance_api` uses the standard
`bdep`-based workflow. `libamddxext` is only supported on Windows (with MSVC
or Clang). For example:

```
git clone .../GPUOpen-gpu_performance_api.git
cd GPUOpen-gpu_performance_api

bdep init -C @msvc cc config.cxx=cl
bdep update
bdep test
```
