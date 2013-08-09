// This file declares the ISpecifyPropertyPages Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyISpecifyPropertyPages : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyISpecifyPropertyPages);
	static ISpecifyPropertyPages *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *GetPages(PyObject *self, PyObject *args);

protected:
	PyISpecifyPropertyPages(IUnknown *pdisp);
	~PyISpecifyPropertyPages();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGSpecifyPropertyPages : public PyGatewayBase, public ISpecifyPropertyPages
{
protected:
	PyGSpecifyPropertyPages(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGSpecifyPropertyPages, ISpecifyPropertyPages, IID_ISpecifyPropertyPages, PyGatewayBase)



	// ISpecifyPropertyPages
	STDMETHOD(GetPages)(
		CAUUID __RPC_FAR * pPages);

};
