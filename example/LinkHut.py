#!/usr/bin/env python3

import os
import sys
import time

lib_dir = os.path.normpath(os.path.dirname(os.path.realpath(__file__)) + '/../lib/')
sys.path.insert(0, lib_dir)

import link

l = link.Link(120)
l.enabled = True
l.startStopSyncEnabled = True

while True:
  s = l.captureSessionState()
  link_time = l.clock().micros();
  tempo_str = "{0:.2f}".format(s.tempo())
  beats_str = "{0:.2f}".format(s.beatAtTime(link_time, 0))
  playing_str = str(s.isPlaying())
  phase = s.phaseAtTime(link_time, 4)
  phase_str = ''
  for x in range(0, 4):
    if x < phase:
      phase_str += 'X'
    else:
      phase_str += "0"
  sys.stdout.write(
      'tempo ' + tempo_str + ' | isPlaying: ' + playing_str + ' | beats ' + beats_str
      + ' | ' + phase_str + '  \r')
  sys.stdout.flush()
  time.sleep(0.02)
