#!/usr/bin/env python3

import os
import sys
import time

lib_dir = os.path.normpath(os.path.dirname(os.path.realpath(__file__)) + '/../lib/')
sys.path.insert(0, lib_dir)

import link

l = link.Link(120)
l.enabled = True

while True:
  t = l.captureTimeline()
  link_time = l.clock().micros();
  tempo_str = "{0:.2f}".format(t.tempo())
  beats_str = "{0:.2f}".format(t.beatAtTime(link_time, 0))
  phase = t.phaseAtTime(link_time, 4)
  phase_str = ''
  for x in range(0, 4):
    if x < phase:
      phase_str += 'X'
    else:
      phase_str += "0"
  sys.stdout.write(
    'tempo ' + tempo_str + ' | beats ' + beats_str + ' | ' + phase_str + '\r')
  sys.stdout.flush()
  time.sleep(0.02)
