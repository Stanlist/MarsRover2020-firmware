
#include "TutorialServo.h"

#include "mbed.h"

TutorialServo::TutorialServo(PinName servoPin, float servoRangeInDegrees, float minPulsewidthInMs,
                             float maxPulsewidthInMs)
    : m_servoPwmOut(servoPin),
      m_servoRangeInDegrees(servoRangeInDegrees),
      m_minPulsewidthInMs(minPulsewidthInMs),
      m_maxPulsewidthInMs(maxPulsewidthInMs) {}

void TutorialServo::setPositionInDegrees(const float degrees) {
  if (degrees > m_servoRangeInDegrees) {
    m_servoPwmOut.pulsewidth_ms(m_maxPulsewidthInMs);
  } else if (degrees < 0) {
    m_servoPwmOut.pulsewidth_ms(m_minPulsewidthInMs);
  } else {
    m_servoPwmOut.pulsewidth_ms(m_minPulsewidthInMs +
                                ((m_maxPulsewidthInMs - m_minPulsewidthInMs) / m_servoRangeInDegrees) * degrees);
  }
}

float TutorialServo::getServoRangeInDegrees() const {
  return m_servoRangeInDegrees;
}

float TutorialServo::getMinPulseWidthInMs() const {
  return m_minPulsewidthInMs;
}

float TutorialServo::getMaxPulseWidthInMs() const {
  return m_maxPulsewidthInMs;
}
