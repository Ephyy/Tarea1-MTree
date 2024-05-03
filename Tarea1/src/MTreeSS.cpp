#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "Node.h"
#include "Cluster.h"

using namespace std;

class MTreeBySS {
    public:
        Node &root;
        double max_size;
        double min_size;

        MTreeBySS(double max_size, double min_size, Node &root) : root(root) {
            this->max_size = max_size;
            this->min_size = min_size;
            // root = new MTreeNode();
        }

    
        // Function OutputLeafPage(
        // Cin: a set of points of cardinality no
        // greater that will fit into a disk page
        // )
        // Returns a tuple (m,r, a) where:
        //     m is the primary medoid of Cin,
        //     r is called the covering radius,
        //     a is the disk address of the page output.
        tuple<Point, double, Node &> outputLeafPage(Cluster c_in){
            Point g = c_in.set_primary_medoid();
            double r = 0;
            set<Point> C;

            for (Point p : c_in.points) {
                C.insert(Entry(p, NULL, NULL));
                r = max(r, g.distance(p, g));
            }

            set<Point>* a = &C;
            return make_tuple(g, r, a);
        }

        // Function OutputInternalPage (
        // Cmra: a set of (m,r, a) tuples as returned from OutputLeafPage
        // )
        // Returns (M, R, A) where:
        // M is the primary medoid of the set of
        // points Cin = {m|∃(m,r, a) ∈ Cmra},
        // R is called the covering radius,
        // A is the disk address of the page output.
        tuple<Point, double, Node &> outputInternalPage(vector<tuple<Point, double, Node &>> &c_mra);

        // Function BulkLoad(
        // Cin: a set of points in a metric space,
        // CMAX: maximum number of node entries that will fit into a disk page
        // )
        // Returns disk address of root page of constructed M-tree
        Node bulkLoad(vector<Point> &c_in);

        
};