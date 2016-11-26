#include <ableton/Link.hpp>
#include <pybind11/pybind11.h>

PYBIND11_PLUGIN(link) {
  using namespace ableton;
  using namespace pybind11;

  using Clock = Link::Clock;
  using Timeline = Link::Timeline;
  using micros = std::chrono::microseconds;

  module m("link", "Ableton Link");

  class_<Clock>(m, "Clock")
    .def("micros", [](const Clock& clock) {
      return clock.micros().count(); });

  class_<Timeline>(m, "Timeline")
    .def("tempo", &Timeline::tempo)
    .def("setTempo", [](Timeline& timeline, const double tempo, const uint64_t time){
      timeline.setTempo(tempo, micros(time)); })
    .def("beatAtTime", [](Timeline& timeline, uint64_t time, double quantum){
      return timeline.beatAtTime(micros(time), quantum); })
    .def("phaseAtTime", [](Timeline& timeline, uint64_t time, double quantum){
      return timeline.phaseAtTime(micros(time), quantum); })
    .def("timeAtBeat", [](Timeline& timeline, double beat, double quantum) {
      return timeline.timeAtBeat(beat, quantum).count(); })
    .def("requestBeatAtTime", []
      (Timeline& timeline, double beat, uint64_t time, double quantum){
        timeline.requestBeatAtTime(beat, micros(time), quantum); });

  class_<Link>(m, "Link")
    .def(init<const double &>())
    .def_property("enabled", &Link::isEnabled, &Link::enable)
    .def("numPeers", &Link::numPeers)
    .def("clock", &Link::clock)
    .def("captureTimeline", &Link::captureAppTimeline)
    .def("commitTimeline", &Link::commitAppTimeline);

  return m.ptr();
}
