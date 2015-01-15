struct FaceColor {
	int a;
};

//octree chunck format dummy head node
struct OctTreeNode {
	struct OctTreeNode* posXposYposZ; //octant 1	(+ + +)
	struct OctTreeNode* posXposYnegZ; //octant 5	(+ + -)
	struct OctTreeNode* negXposYposZ; //octant 2	(- + +)
	struct OctTreeNode* negXposYnegZ; //octant 6	(- + -)
	struct OctTreeNode* negXnegYposZ; //octant 3	(- - +)
	struct OctTreeNode* negXnegYnegZ; //octant 7	(- - -)
	struct OctTreeNode* posXnegYposZ; //octant 4	(+ - +)
	struct OctTreeNode* posXnegYnegZ; //octant 8	(+ - -)

	struct OctTreeNode* root; //pointer to the root node

	struct FaceColor color; //this is the average color value for this node
	//this is from the center of each ovetree
	int x;
	int y;
	int z;
	//the size of the node total
	int level;
};

struct OctTreeLeafNode{

};