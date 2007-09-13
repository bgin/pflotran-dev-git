#ifndef HDF_H_
#define HDF_H_

#include "include/petsc.h"

#include "hdf5.h"

class HDF {

public:

  HDF(char *filename, int overwrite);
  virtual ~HDF();

  void createGroup(char *group_name);
  void createFileSpace(int rank, int dim0, int dim1, int idim2);
  void createMemorySpace(int rank, int dim0, int dim1, int idim2);
  void createDataSpace(int rank, int dim0, int dim1, int idim2);
  void createDataSpace(hid_t *space_id, int rank, int dim0, int dim1, 
                       int idim2);
  static void createDataSpace(hid_t *space_id, int rank, int dim0, int dim1, 
                              int idim2, int max_dim0, int max_dim1, 
                              int max_dim2);
  void setHyperSlab(int n);
  void setHyperSlab(int n, int stride0);
  void setHyperSlab(int *start, int *stride, int *count, int *block);
  void createDataSet(char *data_set_name, hid_t type, int compress);
  void closeGroup();
  void closeDataSpaces();
  static void closeDataSpace(hid_t *space_id);
  void closeDataSet();
  void writeInt(int *values);
  void writeDouble(double *values);
  void writeString(char *title, char *string);

private:

  hid_t file_id; 
  hid_t grp_id[20]; 
  hid_t file_space_id;
  hid_t memory_space_id;
  hid_t data_set_id; 
  herr_t status;

  int ngrp;

  hsize_t hyperslab_start[3];
  hsize_t hyperslab_stride[3];
  hsize_t hyperslab_count[3];
  hsize_t hyperslab_block[3];
  
};

#endif /*HDF_H_*/
