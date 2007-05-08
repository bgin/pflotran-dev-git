#if (PETSC_VERSION_RELEASE == 1)

#define SNESMonitorSet SNESSetMonitor
#define MatCreateMFFD MatCreateSNESMF
#define MatMFFDSetType MatSNESMFSetType
#define MATMFFD_WP MATSNESMF_WP
#define MatMFFDGetH MatSNESMFGetH
#define MatMFFDSetHHistory MatSNESMFSetHHistory
#define IS_COLORING_GLOBAL IS_COLORING_LOCAL

#endif
