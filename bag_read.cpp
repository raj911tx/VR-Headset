#include <open3d/open3d.hpp>
using namespace open3d;
t::io::RSBagReader bag_reader;
bag_reader.Open(test_data.bag);
auto im_rgbd = bag_reader.NextFrame();
while (!bag_reader.IsEOF()) {
    // process im_rgbd.depth_ and im_rgbd.color_
    im_rgbd = bag_reader.NextFrame();
}
bag_reader.Close();
