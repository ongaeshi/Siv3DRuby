#include "MrbPoint.hpp"

#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/value.h"

//----------------------------------------------------------
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
    mrb_int x, y;
    mrb_get_args(mrb, "ii", &x, &y);

    Point* obj = new Point(x, y);

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

//----------------------------------------------------------
Point* MrbPoint::ToCpp(mrb_state *mrb, mrb_value value)
{
    return ToCpp(mrb, mrb_class_get(mrb, "Point"), value);
}

//----------------------------------------------------------
Point* MrbPoint::ToCpp(mrb_state *mrb, struct RClass *cc, mrb_value value)
{
    if (!mrb_obj_is_instance_of(mrb, value, cc)) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong argument class");
    }

    return static_cast<Point*>(DATA_PTR(value));
}

}
