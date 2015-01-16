/*Contains code that implements the octree in memory
*/

#include <inttypes.h>
/*Store the color value for a face*/
struct FaceColor {
	/*allow for 32 bit color*/
	uint8_t alpha;
	uint8_t red;
	uint8_t green;
	uint8_t blue; 
};

/*octree chunck format dummy head node */
struct OctTreeNode {
	struct OctTreeNode* posXposYposZ; /* octant 1	(+ + +) */
	struct OctTreeNode* posXposYnegZ; /*octant 5	(+ + -) */
	struct OctTreeNode* negXposYposZ; /*octant 2	(- + +) */
	struct OctTreeNode* negXposYnegZ; /*octant 6	(- + -) */
	struct OctTreeNode* negXnegYposZ; /*octant 3	(- - +) */
	struct OctTreeNode* negXnegYnegZ; /*octant 7	(- - -) */
	struct OctTreeNode* posXnegYposZ; /*octant 4	(+ - +) */
	struct OctTreeNode* posXnegYnegZ; /*octant 8	(+ - -) */

	struct OctTreeNode* parent; /*pointer to the root node */

	/*
	this is the average color value for this node
	the face normal to the vector only along one axis
	posX is the face normal to the vector (+1,0,0)
	this allows the voxel to have different colors per face
	*/
	struct FaceColor posX;
	struct FaceColor negX;
	struct FaceColor posY;
	struct FaceColor negY;
	struct FaceColor posZ;
	struct FaceColor negZ;
	/*this is from the center of each ovetree */
	int x;
	int y;
	int z;
	/*the size of the node total*/
	int level;
};

/* used to implement a block */
struct OctTreeLeafNode{


	/*
	this is the average color value for this node
	the face normal to the vector only along one axis
	posX is the face normal to the vector (+1,0,0)
	this allows the voxel to have different colors per face 
	*/
	struct FaceColor posX;
	struct FaceColor negX;
	struct FaceColor posY;
	struct FaceColor negY;
	struct FaceColor posZ;
	struct FaceColor negZ;
};

/*PROTOTYPES*/
/*allocate a new node */
void newNode(struct OctTreeNode* to_allocate);
/*return a face color */
uint32_t getFaceColor(const struct OctTreeNode*, uint8_t face);
/*set the face color to arbitrary face */
void setFaceColor(struct OctTreeNode*, uint8_t face);


