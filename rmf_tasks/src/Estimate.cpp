/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <rmf_tasks/Estimate.hpp>

namespace rmf_tasks {

//==============================================================================
class Estimate::Implementation
{
public:

  Implementation(agv::State finish_state, rmf_traffic::Time wait_until)
  : _finish_state(std::move(finish_state)),
    _wait_until(std::move(wait_until))
  {}

  agv::State _finish_state;
  rmf_traffic::Time _wait_until;
};

//==============================================================================
Estimate::Estimate(agv::State finish_state, rmf_traffic::Time wait_until)
: _pimpl(rmf_utils::make_impl<Implementation>(
    std::move(finish_state), std::move(wait_until)))
{}

//==============================================================================
agv::State Estimate::finish_state() const
{
  return _pimpl->_finish_state;
}

//==============================================================================
Estimate& Estimate::finish_state(agv::State new_finish_state)
{
  _pimpl->_finish_state = std::move(new_finish_state);
  return *this;
}

//==============================================================================
rmf_traffic::Time Estimate::wait_until() const
{
  return _pimpl->_wait_until;
}

//==============================================================================
Estimate& Estimate::wait_until(rmf_traffic::Time new_wait_until)
{
  _pimpl->_wait_until = std::move(new_wait_until);
  return *this;
}

//==============================================================================
} // namespace rmf_tasks