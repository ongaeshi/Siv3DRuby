#include <Siv3D.hpp>
// #include "MrbCircle.hpp"
#include "MrbMisc.hpp"
#include "MrbPoint.hpp"
#include "mruby.h"
#include "mruby/compile.h"

extern void mrb_siv3druby_circle_init(mrb_state *mrb);

void Main()
{
    mrb_state* mrb = mrb_open();

    siv3druby::MrbMisc::Init(mrb);
    mrb_siv3druby_circle_init(mrb);
    siv3druby::MrbPoint::Init(mrb);

    FILE* fp;
    fopen_s(&fp, "main.rb", "r");
    {
        mrb_value ret = mrb_load_file(mrb, fp);
    }
    fclose(fp);

    mrb_close(mrb);
}
