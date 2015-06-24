!-------------------------------
!  coarray intrinsics
!-------------------------------
!! inquiry functions
!     integer, external :: image_index
!     integer, external :: lcobound, ucobound

!! transformation functions
      integer, external :: num_images, this_image

      interface xmpf_this_image
         function xmpf_this_image_coarray_wrap(descptr, corank) result(image)
           integer(8), intent(in) :: descptr
           integer, intent(in) :: corank
           integer image(corank)
         end function xmpf_this_image_coarray_wrap
         function xmpf_this_image_coarray_dim(descptr, corank, dim) result(coindex)
           integer(8), intent(in) :: descptr
           integer, intent(in) :: corank, dim
           integer coindex
         end function xmpf_this_image_coarray_dim
      end interface


!-------------------------------
!  coarray runtime interface
!-------------------------------
!! synchronization
      include "xmp_coarray_sync.h"

!! reference of coindexed objects
      include "xmp_coarray_get.h"

!! allocate statement
      include "xmp_coarray_alloc.h"

!! reduction subroutines
!!      include "xmp_coarray_reduction.h"
      interface co_sum
         subroutine co_sum_i4(source, result)
           integer(4) :: source, result
         end subroutine co_sum_i4
         subroutine co_sum_r4(source, result)
           real(4) :: source, result
         end subroutine co_sum_r4
         subroutine co_sum_r8(source, result)
           real(8) :: source, result
         end subroutine co_sum_r8
      end interface

      interface co_max
         subroutine co_max_i4(source, result)
           integer(4) :: source, result
         end subroutine co_max_i4
         subroutine co_max_r4(source, result)
           real(4) :: source, result
         end subroutine co_max_r4
         subroutine co_max_r8(source, result)
           real(8) :: source, result
         end subroutine co_max_r8
      end interface

      interface co_min
         subroutine co_min_i4(source, result)
           integer(4) :: source, result
         end subroutine co_min_i4
         subroutine co_min_r4(source, result)
           real(4) :: source, result
         end subroutine co_min_r4
         subroutine co_min_r8(source, result)
           real(8) :: source, result
         end subroutine co_min_r8
      end interface

!! hidden utilities
      integer, external :: xmpf_coarray_allocated_bytes
      integer, external :: xmpf_coarray_garbage_bytes
