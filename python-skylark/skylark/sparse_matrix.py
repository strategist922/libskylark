import lib
from ctypes import byref, c_void_p, c_int, POINTER


class SparseMatrix(object):
  """  This implements a very crude CSC sparse matrix container only intended to
    hold local sparse matrices.
  
    Row indices are not sorted.
    Structure is always constants, and can only be attached by Attached.
    Values of non-zeros can be modified.
  """

  def __init__(self, size=0):
    self._obj = c_void_p()
    lib.callsl("sl_create_sparse_matrix", "SparseMatrix", size, byref(self._obj))    
  
  def height(self):
    height = c_int()
    lib.callsl("sl_sparse_matrix_height", byref(height), self._obj)
    return height.value

  def width(self):
    width = c_int()
    lib.callsl("sl_sparse_matrix_width", byref(width), self._obj)
    return width.value

  def nonzeros(self):
    nonzeros = c_int()
    lib.callsl("sl_sparse_matrix_nonzeros", byref(nonzeros), self._obj)
    return nonzeros.value

