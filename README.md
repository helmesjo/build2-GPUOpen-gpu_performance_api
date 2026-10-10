# GPUOpen-gpu_performance_api - AMD GPU Performance API (GPUPerfAPI)

This is a `build2` package repository for
[`gpu_performance_api`](https://github.com/GPUOpen-Tools/gpu_performance_api),
the AMD GPU Performance API (GPUPerfAPI, or GPA) library which provides access
to GPU performance counters of AMD Radeon GPUs.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libgpuperfapi-headers` in your `build2`-based project, then instead see the
accompanying [`PACKAGE-README.md`](libgpuperfapi-headers/PACKAGE-README.md)
file.

The development setup for `GPUOpen-gpu_performance_api` uses the standard `bdep`-based workflow.
For example:

```
git clone .../GPUOpen-gpu_performance_api.git
cd GPUOpen-gpu_performance_api

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
