#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class GaelRackFxAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit GaelRackFxAudioProcessorEditor (GaelRackFxAudioProcessor&);
    ~GaelRackFxAudioProcessorEditor() override = default;
    void paint (juce::Graphics&) override;
    void resized() override;
private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    GaelRackFxAudioProcessor& processor;
    juce::Label title, subtitle, presetsLabel, micLabel;
    juce::ComboBox presets, microphone;
    juce::TextButton power { "ON" };
    juce::Slider input, mix, output, low, mid, high, compression, saturation, air, afro;
    std::vector<std::unique_ptr<SliderAttachment>> attachments;
    void styleSlider (juce::Slider&, juce::Colour);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GaelRackFxAudioProcessorEditor)
};
