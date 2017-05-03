#include "MrbPoint.hpp"

#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/value.h"

namespace siv3druby {

namespace {
Point& toCpp(mrb_value self)
{
    return *((Point*)DATA_PTR(self));
}

void free(mrb_state *mrb, void *p)
{
    if (p) {
        delete ((Point*)p);
    }
}

struct mrb_data_type data_type = { "siv3d_point", free };

mrb_value initialize(mrb_state *mrb, mrb_value self)
{
    Point* obj = new Point(100, 100);
    mrb_data_init(self, obj, &data_type);
    return self;
}
}

//----------------------------------------------------------
void MrbPoint::Init(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Point", mrb->object_class);

    mrb_define_method(mrb, cc, "initialize", initialize, MRB_ARGS_REQ(2));
}

}
