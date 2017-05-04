#include "MrbFont.hpp"

#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/value.h"

//----------------------------------------------------------
namespace siv3druby {
namespace {
Font& toCpp(mrb_value self)
{
    return *((Font*)DATA_PTR(self));
}

void free(mrb_state *mrb, void *p)
{
    if (p) {
        delete ((Font*)p);
    }
}

struct mrb_data_type data_type = { "siv3d_font", free };

mrb_value initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int size;
    mrb_get_args(mrb, "i", &size);

    Font* obj = new Font(size);

    mrb_data_init(self, obj, &data_type);
    return self;
}
}

//----------------------------------------------------------
void MrbFont::Init(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Font", mrb->object_class);

    mrb_define_method(mrb, cc, "initialize", initialize, MRB_ARGS_REQ(1));
}

//----------------------------------------------------------
mrb_value MrbFont::ToMrb(mrb_state *mrb, Font *ptr)
{
    return ToMrb(mrb, mrb_class_get(mrb, "Font"), ptr);
}

//----------------------------------------------------------
mrb_value MrbFont::ToMrb(mrb_state *mrb, struct RClass *cc, Font *ptr)
{
    struct RData *data = mrb_data_object_alloc(mrb, cc, ptr, &data_type);
    return mrb_obj_value(data);
}

//----------------------------------------------------------
Font* MrbFont::ToCpp(mrb_state *mrb, mrb_value value)
{
    return ToCpp(mrb, mrb_class_get(mrb, "Font"), value);
}

//----------------------------------------------------------
Font* MrbFont::ToCpp(mrb_state *mrb, struct RClass *cc, mrb_value value)
{
    if (!mrb_obj_is_instance_of(mrb, value, cc)) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong argument class");
    }

    return static_cast<Font*>(DATA_PTR(value));
}

}
