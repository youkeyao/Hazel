#pragma once

#define GLFW_INCLUDE_NONE

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>

#include "core/log.h"

#define BIT(x) (1 << x)
#define HZ_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)