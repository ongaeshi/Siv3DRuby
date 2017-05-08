#include "MrbDrawableString.hpp"

#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/value.h"

//----------------------------------------------------------
namespace siv3druby {
namespace {
DrawableString& toCpp(mrb_value self)
{
    return *((DrawableString*)DATA_PTR(self));
}

void free(mrb_state *mrb, void *p)
{
    if (p) {
        delete ((DrawableString*)p);
    }
}

struct mrb_data_type data_type = { "siv3d_drawable_string", free };

mrb_value draw(mrb_state *mrb, mrb_value self)
{
    toCpp(self).draw();
    return mrb_nil_value();
}
}

//----------------------------------------------------------
void MrbDrawableString::Init(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "DrawableString", mrb->object_class);

    mrb_define_method(mrb, cc, "draw", draw, MRB_ARGS_NONE());
}

//----------------------------------------------------------
mrb_value MrbDrawableString::ToMrb(mrb_state *mrb, DrawableString *ptr)
{
    return ToMrb(mrb, mrb_class_get(mrb, "DrawableString"), ptr);
}

//----------------------------------------------------------
mrb_value MrbDrawableString::ToMrb(mrb_state *mrb, struct RClass *cc, DrawableString *ptr)
{
    struct RData *data = mrb_data_object_alloc(mrb, cc, ptr, &data_type);
    return mrb_obj_value(data);
}

//----------------------------------------------------------
DrawableString* MrbDrawableString::ToCpp(mrb_state *mrb, mrb_value value)
{
    return ToCpp(mrb, mrb_class_get(mrb, "DrawableString"), value);
}

//----------------------------------------------------------
DrawableString* MrbDrawableString::ToCpp(mrb_state *mrb, struct RClass *cc, mrb_value value)
{
    if (!mrb_obj_is_instance_of(mrb, value, cc)) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong argument class");
    }

    return static_cast<DrawableString*>(DATA_PTR(value));
}

}
