import wave
import math

SAMPLE_RATE = 22050
DURATION = 1.5

NOTES = {
    'C2': 65.41,
    'E2': 82.41,
    'G2': 98.00,
    'C3': 130.81
}

def generate_boot_sound():
    file_name = "boot.wav"
    num_samples = int(SAMPLE_RATE * DURATION)
    
    with wave.open(file_name, 'wb') as wav_file:
        wav_file.setnchannels(1)
        wav_file.setsampwidth(1)
        wav_file.setframerate(SAMPLE_RATE)
        
        audio_bytes = bytearray()
        
        for i in range(num_samples):
            t = float(i) / SAMPLE_RATE
            envelope = max(0.0, 1.0 - (t / DURATION))
            
            signal = 0.0
            for note, freq in NOTES.items():
                signal += math.sin(2.0 * math.pi * freq * t)
            
            signal = (signal / len(NOTES)) * envelope
            sample = int((signal * 127) + 128)
            audio_bytes.append(sample)
            
        wav_file.writeframes(audio_bytes)

if __name__ == "__main__":
    generate_boot_sound()
  
