#ifndef _ELLIPSOID_CAD_
#define _ELLIPSOID_CAD_

#include <stdint.h>
/*To voxelise a surface we test for voxels that have a
center inside the surface. */


struct Point2D {
	uint32_t x;
	uint32_t y;
};

struct Point3D {
	uint32_t x;
	uint32_t y;
	uint32_t z;
};

void ellipseLinearGenerator(uint32_t A, uint32_t B, struct Point2D* result);



#endif