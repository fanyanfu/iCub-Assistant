## A Dynamical System Approach for Adaptive Grasping, Navigation and Co-Manipulation with Humanoid Robots

### Abstract
<div style="text-align: justify">
In this work [1], we present an integrated approach that provides compliant control of an iCub humanoid robot and adaptive reaching, grasping, navigating and co-manipulating. We use state-dependent dynamical systems (DS) to (i) coordinate and drive the robot's hands an object in position and orientation to grasp an object [2], and (ii) drive the robot's base while walking/navigating. The use of DS as motion generators allows us to adapt smoothly as the object moves and to re-plan on-line motion of arms and body to reach the object's new location. The desired trajectory generated by the DS are used in combination with a whole-body compliant control strategy that absorbs perturbations while walking [3] and offers compliant behaviors for grasping and manipulation tasks [4]. The desired dynamics for arm and body can be learned from demonstrations [5].  By integrating these components we achieve unprecedented adaptive behaviors for whole body manipulation. We showcase this in simulations and real-world experiments where iCub robots  (i) walk-to-grasp objects, (ii) follow a human (or another iCub) through interaction and (iii) learn to navigate or co-manipulate an object from human guided demonstrations; whilst being robust to changing targets and perturbations.
</div>
<br>

<div style="text-align: justify">
In more detail, the novelty of this work lies in the integration and extension of three sets of
techniques developed previously by the coauthors, namely DS-based coordinated planning of reach to grasp motion
[2], whole-body balancing [4] and compliant walking [3]. Finally, we use the adaptive walking approach to collect
trajectories and use them to learn desired complex navigation
tasks with a state-of-the-art DS-based learning scheme [5]
</div>

### Video of Approach and Robot Experiments
- Supplementary video for ICRA submission:
<iframe width="560" height="315" src="https://www.youtube.com/embed/X-XwPxNrjFo" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

- Complementary video for adaptive co-manipulation with master-slave strategy simulation:
<iframe width="560" height="315" src="https://www.youtube.com/embed/nHgS8ADImYA" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

- Complementary video for co-manipulation with learned DS:
<iframe width="560" height="315" src="https://www.youtube.com/embed/3z52S-u1qaI" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### Code
Following we list all of the code repositories made available for this project, including:
- Code for executing the control framework in C++:  
[https://github.com/epfl-lasa/iCub-Assistant](https://github.com/epfl-lasa/iCub-Assistant)

- Code for learning DS-based navigation behaviors in MATLAB:  
[https://nbfigueroa.github.io/pc-gmm-ds-learning/](https://nbfigueroa.github.io/pc-gmm-ds-learning/)



### References
> [1] Figueroa, N., Faraji, S., Koptev, M. and Billard, A. (2019) "A Dynamical System Approach for Adaptive Grasping, Navigation and Co-Manipulation with Humanoid Robots". In proceedings of the IEEE International Conference on Robotics and Automation (ICRA-2020). Paris, France [pdf-link](https://infoscience.epfl.ch/record/277616/)   
> [2] S. Mirrazavi, N. Figueroa, and A. Billard, “A unified framework for coordinated multi-arm motion planning,” The International Journal of Robotics Research, vol. 37, no. 10, pp. 1205–1232, 2018.   
> [3] S. Faraji, P. Mullhaupt, and A. Ijspeert, “Imprecise dynamic walking with time-projection control,” [arxiv](https://infoscience.epfl.ch/record/260430?ln=en), 2018.   
> [4] S. Faraji and A. J. Ijspeert, “Singularity-tolerant inverse kinematics for bipedal robots: An efficient use of computational power to reduce energy consumption,” IEEE Robotics and Automation Letters, vol. 2, no. 2, pp. 1132–1139, April 2017.  
> [5] N. Figueroa and A. Billard, “A physically-consistent bayesian non-parametric mixture model for dynamical system learning,” in Proceedings of The 2nd Conference on Robot Learning, ser. Proceedings of Machine Learning Research, vol. 87. PMLR, 29–31 Oct 2018, pp. 927–946 . 

### Contact 
[Nadia Figueroa](http://lasa.epfl.ch/people/member.php?SCIPER=238387) (nadia.figueroafernandez AT epfl dot ch) and/or [Salman Faraji](https://salmanfaraji.github.io/) (salman.faraji AT epfl dot ch)

### Acknowledgments
This work was supported by the European Community Horizon 2020 Research and Innovation pro-
gramme ICT-23-2014, grant agreement 644727-[Cogimon](https://cogimon.eu/cognitive-interaction-motion-cogimon) and
643950-[SecondHands](https://secondhands.eu/).

 
