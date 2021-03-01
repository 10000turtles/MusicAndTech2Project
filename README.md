# Music and Tech 2 Project - Markov Chain Music

Hi. This project is meant to be a deep exploration into markov chains. Below I outline some of the hopes I have for this project,

  -The sample size of personal midi data. I only had 1 solo in the original set so it would be nice to have closer to 50, maybe across multiple songs of mine.
  -The order of the markov chains. The original project was 2nd order but it can be extended to nth order. This is complimented by the larger data set and means more of the markov table can be filled out.
  -Adding in variation in dynamics and rhythm. My original project had only variation in pitch and so that could be expanded as well.
  -The ease of use for going to and from MIDI. In the original project, I manually transfered MIDI files before and after they were edited. Now I would like to use something a little more robust to help automate any generation.
  -Adding intensity to the solos. Every solo has its own intensity curve and I would like to capture that and have the markov model take it into effect.
  -Adding more context to the solos. This context is just more values that aren't the previous notes like the root note of the chord, at what point in the measure you play the note, I'm sure there are other things to add.
  -Allowing for natural chords instead of chord clumps.

