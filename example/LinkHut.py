#!/usr/bin/env python

from os import path
import sys
import time

lib_dir = path.normpath(path.dirname(path.realpath(__file__)) + '/..')
sys.path.insert(0, lib_dir)

import link

l = link.Link(120)
l.enabled = True
l.startStopSyncEnabled = True

try:
  while True:
    s = l.captureSessionState()
    link_time = l.clock().micros();
    tempo_str = '{0:.2f}'.format(s.tempo())
    beats_str = '{0:.2f}'.format(s.beatAtTime(link_time, 0))
    playing_str = str(s.isPlaying())
    phase = s.phaseAtTime(link_time, 4)
    phase_str = ''
    for x in range(0, 4):
      if x < phase:
        phase_str += 'X'
      else:
        phase_str += '0'
    sys.stdout.write(
      'tempo ' + tempo_str + ' | playing: ' + playing_str + ' | beats ' + beats_str
      + ' | ' + phase_str + '  \r')
    sys.stdout.flush()
    time.sleep(0.02)
except KeyboardInterrupt:
    pass
