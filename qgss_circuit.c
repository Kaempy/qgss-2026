
#include <Python.h>
#include <qiskit.h>
#include <stdint.h>

static PyObject *build_special_circuit(PyObject *self, PyObject *args) {
    QkCircuit *qc = qk_circuit_new(6, 0);

    // TODO 1: Apply H to qubit 0.
    //   Use qk_circuit_gate with QkGate_H. See the C API reference.
    uint32_t qubit0[] = {0};
    qk_circuit_gate(qc, QkGate_H, qubit0, NULL);

    // TODO 2: Apply X to qubit 1.
    //   Use qk_circuit_gate with QkGate_X.
    uint32_t qubit1[] = {1};
    qk_circuit_gate(qc, QkGate_X, qubit1, NULL);

    // TODO 3: Add a CNOT chain. Control is qubit 0, targets are 1 to 5.
    //   For each target, call qk_circuit_gate with QkGate_CX and a {control, target} array.
    //   A for loop works here.
    for (uint32_t target = 1; target < 6; target++) {
        uint32_t control_target[] = {0, target};
        qk_circuit_gate(qc, QkGate_CX, control_target, NULL);
    }

    return qk_circuit_to_python_full(qc);
}

static PyMethodDef methods[] = {
    {"build_special_circuit", build_special_circuit, METH_NOARGS, "Build the special circuit."},
    {NULL, NULL, 0, NULL},
};
static struct PyModuleDef moduledef = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "qgss_circuit",
    .m_methods = methods,
};
PyMODINIT_FUNC PyInit_qgss_circuit(void) {
    if (qk_import() < 0) {
        return NULL;
    }
    return PyModuleDef_Init(&moduledef);
}
