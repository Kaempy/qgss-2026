# Qiskit Global Summer School 2026: my lab work

My completed labs from IBM's **[Qiskit Global Summer School 2026 (QGSS26)](https://www.credly.com/badges/1497c2f1-b5b9-4f87-8c11-fd4100028beb/print)**. I received the **QGSS26 Quantum Excellence** recognition from IBM.

<!-- TODO(Mary): add a link to the certificate or badge (e.g. Credly) here. -->

> The lab notebooks are written by the QGSS26 organisers at IBM Quantum. This repository holds **my solutions and outputs**: every graded exercise was completed and passed the autograder. Where I ran on IBM Quantum hardware, the backend is shown in the notebook output.

## What the labs covered

| Lab                          | Topic                                                         | What I did                                                                                                                                                                                                                                                                                                        |
| ---------------------------- | ------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Lab 0](lab_00.ipynb)        | **Qiskit patterns** (map → optimize → execute → post-process) | Built and analysed first circuits with the Sampler and Estimator primitives. Visualised multi-qubit states (statevector, QSphere). Completed the optional chapter that builds the same circuit through **Qiskit's C API** and checks it in Python ([`qgss_circuit.c`](qgss_circuit.c), [`setup.py`](setup.py)).   |
| [Lab 1](lab_01.ipynb)        | **Circuits for real hardware**                                | Bell and GHZ states. Circuit-depth analysis and depth reduction (start-from-the-middle, recursive fan-out). Built a depth-5, 16-qubit GHZ state. Nearest-neighbour GHZ using the bridge-gate identity. Layouts on heavy-hex topology, up to a **64-qubit GHZ** challenge.                                         |
| [Lab 2](lab_02.ipynb)        | **Noise, backends and benchmarking**                          | Backend-aware noisy simulation. Depolarizing, Pauli and thermal-relaxation (T₁/T₂) noise models. Compared the Heron and Nighthawk architectures. Built a **dynamic-circuit GHZ** with mid-circuit measurement and feed-forward.                                                                                   |
| [Lab 3](lab_03.ipynb)        | **Error mitigation as a tool for quantum advantage**          | Pauli twirling and how Paulis propagate through Clifford layers. Learned noise models with `NoiseLearnerV3` and boxed circuits (Samplomatic). Assembled an `Executor` program. Applied all of this to a **Trotterized 1D Ising chain** with the mirror-circuit trick. Explored propagated noise absorption (PNA). |
| [Lab 4a](lab_04/lab4a.ipynb) | **What is quantum advantage?**                                | Criteria for quantum advantage and IBM's Quantum Advantage Tracker. Observable-estimation tasks, including the expectation value of a **Loschmidt-echo** operator.                                                                                                                                                |
| [Lab 4b](lab_04/lab4b.ipynb) | **Optimisation at scale**                                     | Mapped the number-partitioning problem to an Ising Hamiltonian. Compared error suppression and mitigation settings for the Sampler. Scaled up with **Pauli Correlation Encoding**. Bonus: a 1,600-node graph with a custom mitigation configuration and bit-flip post-processing.                                 |
| [Lab 4c](lab_04/lab4c.ipynb) | **Quantum chemistry with SQD**                                | N₂ Hamiltonian, Jordan–Wigner encoding, and the **LUCJ ansatz** mapped to the Nighthawk device. Configuration recovery and the self-consistent **sample-based quantum diagonalization (SQD)** loop. In the scored subspace-freezing exercise my best energy was **−108.8035 Ha**.                                 |

<!-- TODO(Mary): Remove any "Bonus" claim above that you did not complete. Confirm which labs actually ran on hardware (outputs mention ibm_kingston, ibm_marrakesh, ibm_fez) and name them here if you want to. -->

## What I took from it

1. **Hardware shapes the algorithm.** Topology, depth and noise decide what a circuit can actually do. A 64-qubit GHZ state is a routing problem as much as a physics one.
2. **Error mitigation has a cost.** Twirling, noise learning and absorption techniques trade more sampling for less bias. The labs made that trade-off concrete.
3. **Claims of quantum advantage stand or fall on classical verification.** Lab 3's Trotterized Ising chain and Lab 4's Loschmidt-echo observable led directly to my follow-up project, **[tfim-simulability](https://github.com/Kaempy/tfim-simulability)**. It asks where _classical_ tensor-network simulation of the same kind of Ising dynamics breaks down, benchmarked against exact free-fermion solutions.

## Running the notebooks

The labs were run on [qBraid](https://www.qbraid.com/) with the QGSS 2026 environment, or locally with Python 3.12 and Qiskit 2.x. Hardware sections need an IBM Quantum account.

```bash
pip install qiskit qiskit-ibm-runtime qiskit-aer   # plus the per-lab extras listed in each notebook
```

Lab 0's optional C chapter builds a small extension module:

```bash
python setup.py build_ext --inplace
```

## Credits

Lab material © IBM Quantum / Qiskit Global Summer School 2026. My contributions are my solutions, outputs and notes.
