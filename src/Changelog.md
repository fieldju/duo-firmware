  # Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.1.0-rc.2] - 2018-01-09 
### Added
- MIDI channel is stored even when DUO is turned off

## [1.1.0-rc.1] - 2017-12-14 
### Added
- MIDI channel is shown on the keyboard on startup
- MIDI channel is selectable through keyboard keys on startup
- Filtering of midi CC values
- Slider LEDs fade in on startup
- Sidechaining on the kick
- Sequencer stops before entering bootloader (only in DEV_MODE)

### Changed
- Releasing the random button brings you back to the original sequence
- No more clipping when filter and the two oscillators are set to approximately the same frequency and resonance is up

## Unreleased