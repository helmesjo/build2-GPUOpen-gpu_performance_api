# GPUOpen-gpu_performance_api - <SUMMARY>

This is a `build2` package repository for [`GPUOpen-gpu_performance_api`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`GPUOpen-gpu_performance_api` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `GPUOpen-gpu_performance_api` uses the standard `bdep`-based workflow.
For example:

```
git clone .../GPUOpen-gpu_performance_api.git
cd GPUOpen-gpu_performance_api

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
