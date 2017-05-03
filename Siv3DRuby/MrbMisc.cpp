#include "MrbMisc.hpp"

#include "MrbPoint.hpp"
#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/string.h"

//----------------------------------------------------------
namespace siv3druby {

namespace {
static mrb_value println(mrb_state *mrb, mrb_value self)
{
    mrb_value str;
    mrb_get_args(mrb, "S", &str);
    Println(FromUTF8(mrb_string_value_ptr(mrb, str)));
    return mrb_nil_value();
}

static mrb_value wait_key(mrb_state *mrb, mrb_value self)
{
    WaitKey();
    return mrb_nil_value();
}

static mrb_value system_update(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(System::Update());
}

static mrb_value mouse_pos(mrb_state *mrb, mrb_value self)
{
    return MrbPoint::ToMrb(mrb, new Point(Mouse::Pos()));
}
}

//----------------------------------------------------------
void MrbMisc::Init(mrb_state* mrb)
{
    {
        struct RClass *krn = mrb->kernel_module;
        mrb_define_method(mrb, krn, "println", println, MRB_ARGS_REQ(1));
        mrb_define_method(mrb, krn, "wait_key", wait_key, MRB_ARGS_NONE());
    }

    {
        struct RClass *cc = mrb_define_module(mrb, "System");

        mrb_define_class_method(mrb, cc, "update", system_update, MRB_ARGS_NONE());
    }

    {
        struct RClass *cc = mrb_define_module(mrb, "Mouse");

        mrb_define_class_method(mrb, cc, "pos", mouse_pos, MRB_ARGS_NONE());
    }
}

}
