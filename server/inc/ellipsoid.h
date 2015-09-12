#ifndef _ELLIPSOID_CAD_
#define _ELLIPSOID_CAD_

#include <stdint.h>
#include <stdbool.h>
#include "bignum.h"
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
/*For the linear case where we are moving along an ellipse in plane*/
struct Ellipse2DClosure {
	uint32_t A;
	uint32_t B;
	uint64_t x;
	uint64_t y;
	bool isErrorCalculated;
	struct bignum* error;
};
/*For when we are moving along a surface*/
struct Ellipse3DClosure {
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint64_t x;
	uint64_t y;
	uint64_t z;
	bool isErrorCalculated;
	struct bignum* error;
};

void ellipseLinearGenerator(uint32_t A, uint32_t B, struct Point2D* result);
/*get only the next point from the point provided in the closure */
void ellipse2DNext(struct Ellipse2DClosure* closure, struct Point2D* result);
/*get only the next point on the surface in the direction defined
direction = 0 -> move vector is along pos y
direction = 1 -> move vector is along pos z */
void ellipse3DNext(struct Ellipse3DClosure* closure, struct Point3D result, bool direction);

#endif
