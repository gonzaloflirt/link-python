#include <ableton/Link.hpp>
#include <pybind11/pybind11.h>

PYBIND11_PLUGIN(link) {
  using namespace ableton;
  using namespace pybind11;

  using Clock = Link::Clock;
  using SessionState = Link::SessionState;
  using micros = std::chrono::microseconds;

  module m("link", "Ableton Link");

  class_<Clock>(m, "Clock")
    .def("micros", [](const Clock& clock) {
      return clock.micros().count(); });

  class_<SessionState>(m, "SessionState")
    .def("tempo", &SessionState::tempo)
    .def("setTempo", [](SessionState& sessionState, const double tempo, const uint64_t time){
      sessionState.setTempo(tempo, micros(time)); })
    .def("beatAtTime", [](SessionState& sessionState, uint64_t time, double quantum){
      return sessionState.beatAtTime(micros(time), quantum); })
    .def("phaseAtTime", [](SessionState& sessionState, uint64_t time, double quantum){
      return sessionState.phaseAtTime(micros(time), quantum); })
    .def("timeAtBeat", [](SessionState& sessionState, double beat, double quantum) {
      return sessionState.timeAtBeat(beat, quantum).count(); })
    .def("requestBeatAtTime", []
      (SessionState& sessionState, double beat, uint64_t time, double quantum){
        sessionState.requestBeatAtTime(beat, micros(time), quantum); });

  class_<Link>(m, "Link")
    .def(init<const double &>())
    .def_property("enabled", &Link::isEnabled, &Link::enable)
    .def("numPeers", &Link::numPeers)
    .def("clock", &Link::clock)
    .def("captureSessionState", &Link::captureAppSessionState)
    .def("commitSessionState", &Link::commitAppSessionState);

  return m.ptr();
}
