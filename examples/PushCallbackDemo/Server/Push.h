// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.12.
// **********************************************************************

#ifndef __PUSH_H_
#define __PUSH_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"
#include "servant/Application.h"


namespace TestApp
{

    /* callback of async proxy for client */
    class PushPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~PushPrxCallback(){}
        virtual void callback_pushMsg(tars::Int32 ret,  const std::string& sRsp)
        { throw std::runtime_error("callback_pushMsg() override incorrect."); }
        virtual void callback_pushMsg_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_pushMsg_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __Push_all[]=
            {
                "pushMsg"
            };
            auto it = _msg_->response->status.find("TARS_FUNC");
            pair<string*, string*> r = equal_range(__Push_all, __Push_all+1, (it==_msg_->response->status.end())?_msg_->request.sFuncName:it->second);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Push_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_pushMsg_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    std::string sRsp;
                    _is.read(sRsp, 1, true);
                    ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
                    if (_pSptd_ && _pSptd_->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                            _p_->value["sRsp"] = tars::JsonOutput::writeJson(sRsp);
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "pushMsg", 0, _trace_param_, "");
                    }

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(_msg_->response->context);

                    callback_pushMsg(_ret, sRsp);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<PushPrxCallback> PushPrxCallbackPtr;

    //callback of promise async proxy for client
    class PushPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~PushPrxCallbackPromise(){}
    public:
        struct PromisepushMsg: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            std::string sRsp;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< PushPrxCallbackPromise::PromisepushMsg > PromisepushMsgPtr;

        PushPrxCallbackPromise(const tars::Promise< PushPrxCallbackPromise::PromisepushMsgPtr > &promise)
        : _promise_pushMsg(promise)
        {}
        
        virtual void callback_pushMsg(const PushPrxCallbackPromise::PromisepushMsgPtr &ptr)
        {
            _promise_pushMsg.setValue(ptr);
        }
        virtual void callback_pushMsg_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:pushMsg_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_pushMsg.setException(tars::copyException(str, ret));
        }

    protected:
        tars::Promise< PushPrxCallbackPromise::PromisepushMsgPtr > _promise_pushMsg;

    public:
        virtual int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __Push_all[]=
            {
                "pushMsg"
            };

            pair<string*, string*> r = equal_range(__Push_all, __Push_all+1, string(_msg_->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Push_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_pushMsg_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);

                    PushPrxCallbackPromise::PromisepushMsgPtr ptr = new PushPrxCallbackPromise::PromisepushMsg();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                        _is.read(ptr->sRsp, 1, true);
                    }
                    catch(std::exception &ex)
                    {
                        callback_pushMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_pushMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = _msg_->response->context;

                    callback_pushMsg(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<PushPrxCallbackPromise> PushPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class PushCoroPrxCallback: public PushPrxCallback
    {
    public:
        virtual ~PushCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __Push_all[]=
            {
                "pushMsg"
            };

            pair<string*, string*> r = equal_range(__Push_all, __Push_all+1, string(_msg_->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Push_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_pushMsg_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        std::string sRsp;
                        _is.read(sRsp, 1, true);
                        setResponseContext(_msg_->response->context);

                        callback_pushMsg(_ret, sRsp);

                    }
                    catch(std::exception &ex)
                    {
                        callback_pushMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_pushMsg_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<PushCoroPrxCallback> PushCoroPrxCallbackPtr;

    /* proxy for client */
    class PushProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 pushMsg(std::string &sRsp,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(sRsp, 1);
            ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                _pSptd_->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "pushMsg", 0, _trace_param_, "");
            }

            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"pushMsg", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(sRsp, 1, true);
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _p_->value["sRsp"] = tars::JsonOutput::writeJson(sRsp);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "pushMsg", 0, _trace_param_, "");
            }

            return _ret;
        }

        void async_pushMsg(PushPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                _pSptd_->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "pushMsg", 0, _trace_param_, "");
            }
            tars_invoke_async(tars::TARSNORMAL,"pushMsg", _os, context, _mStatus, callback);
        }
        
        tars::Future< PushPrxCallbackPromise::PromisepushMsgPtr > promise_async_pushMsg(const map<string, string>& context)
        {
            tars::Promise< PushPrxCallbackPromise::PromisepushMsgPtr > promise;
            PushPrxCallbackPromisePtr callback = new PushPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"pushMsg", _os, context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_pushMsg(PushCoroPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"pushMsg", _os, context, _mStatus, callback, true);
        }

        PushProxy* tars_hash(uint32_t key)
        {
            return (PushProxy*)ServantProxy::tars_hash(key);
        }

        PushProxy* tars_consistent_hash(uint32_t key)
        {
            return (PushProxy*)ServantProxy::tars_consistent_hash(key);
        }

        PushProxy* tars_open_trace(bool traceParam = false)
        {
            return (PushProxy*)ServantProxy::tars_open_trace(traceParam);
        }

        PushProxy* tars_set_timeout(int msecond)
        {
            return (PushProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "PushProxy"; }
    };
    typedef tars::TC_AutoPtr<PushProxy> PushPrx;

    /* servant for server */
    class Push : public tars::Servant
    {
    public:
        virtual ~Push(){}
        virtual tars::Int32 pushMsg(std::string &sRsp,tars::TarsCurrentPtr _current_) = 0;
        static void async_response_pushMsg(tars::TarsCurrentPtr _current_, tars::Int32 _ret, const std::string &sRsp)
        {
            size_t _rsp_len_ = 0;
            if (_current_->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                _tarsAttr_.setVersion(_current_->getRequestVersion());
                _tarsAttr_.put("", _ret);
                _tarsAttr_.put("tars_ret", _ret);
                _tarsAttr_.put("sRsp", sRsp);

                vector<char> sTupResponseBuffer;
                _tarsAttr_.encode(sTupResponseBuffer);
                _current_->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
                _rsp_len_ = sTupResponseBuffer.size();
            }
            else if (_current_->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["sRsp"] = tars::JsonOutput::writeJson(sRsp);
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                _current_->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
                _rsp_len_ = sJsonResponseBuffer.size();
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(sRsp, 1);

                _rsp_len_ = _os.getLength();
                _current_->sendResponse(tars::TARSSERVERSUCCESS, _os);
            }
            if (_current_->isTraced())
            {
                string _trace_param_;
                int _trace_param_flag_ = ServantProxyThreadData::needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _current_->getTraceKey(), _rsp_len_);
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _p_->value["sRsp"] = tars::JsonOutput::writeJson(sRsp);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_current_->getTraceKey(), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "pushMsg", 0, _trace_param_, "");
            }

        }
        static void async_response_push_pushMsg(tars::CurrentPtr _current_, tars::Int32 _ret, const std::string &sRsp, const map<string, string> &_context = tars::Current::TARS_STATUS())
        {
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(sRsp, 1);

                _current_->sendPushResponse( tars::TARSSERVERSUCCESS ,"pushMsg", _os, _context);
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __TestApp__Push_all[]=
            {
                "pushMsg"
            };

            pair<string*, string*> r = equal_range(__TestApp__Push_all, __TestApp__Push_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __TestApp__Push_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    std::string sRsp;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                        _tarsAttr_.setVersion(_current->getRequestVersion());
                        _tarsAttr_.decode(_current->getRequestBuffer());
                        _tarsAttr_.getByDefault("sRsp", sRsp, sRsp);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(sRsp, _jsonPtr->value["sRsp"], false);
                    }
                    else
                    {
                        _is.read(sRsp, 1, false);
                    }
                    ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
                    if (_pSptd_ && _pSptd_->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_SR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SR), TRACE_ANNOTATION_SR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "pushMsg", 0, _trace_param_, "");
                    }

                    tars::Int32 _ret = pushMsg(sRsp, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                            _tarsAttr_.setVersion(_current->getRequestVersion());
                            _tarsAttr_.put("", _ret);
                            _tarsAttr_.put("tars_ret", _ret);
                            _tarsAttr_.put("sRsp", sRsp);
                            _tarsAttr_.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["sRsp"] = tars::JsonOutput::writeJson(sRsp);
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(sRsp, 1);
                            _os.swap(_sResponseBuffer);
                        }
                        if (_pSptd_ && _pSptd_->_traceCall)
                        {
                            string _trace_param_;
                            int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _sResponseBuffer.size());
                            if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                            {
                                tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                                _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                                _p_->value["sRsp"] = tars::JsonOutput::writeJson(sRsp);
                                _trace_param_ = tars::TC_Json::writeValue(_p_);
                            }
                            else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                            {
                                _trace_param_ = "{\"trace_param_over_max_len\":true}";
                            }
                            TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "pushMsg", 0, _trace_param_, "");
                        }

                    }
                    else if(_pSptd_ && _pSptd_->_traceCall)
                    {
                        _current->setTrace(_pSptd_->_traceCall, _pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS));
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
