# Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

macro(generate_sources_for_autotools)
    set(fastrtps_SOURCES_TMP fastdds/log/Log.cpp;fastdds/log/StdoutConsumer.cpp;fastdds/log/FileConsumer.cpp;rtps/common/Time_t.cpp;rtps/resources/ResourceEvent.cpp;rtps/resources/TimedEvent.cpp;rtps/resources/TimedEventImpl.cpp;rtps/resources/AsyncWriterThread.cpp;rtps/resources/AsyncInterestTree.cpp;rtps/writer/LivelinessManager.cpp;rtps/writer/RTPSWriter.cpp;rtps/writer/StatefulWriter.cpp;rtps/writer/ReaderProxy.cpp;rtps/writer/StatelessWriter.cpp;rtps/writer/ReaderLocator.cpp;rtps/history/CacheChangePool.cpp;rtps/history/History.cpp;rtps/history/WriterHistory.cpp;rtps/history/ReaderHistory.cpp;rtps/reader/WriterProxy.cpp;rtps/reader/StatefulReader.cpp;rtps/reader/StatelessReader.cpp;rtps/reader/RTPSReader.cpp;rtps/messages/RTPSMessageCreator.cpp;rtps/messages/RTPSMessageGroup.cpp;rtps/messages/RTPSGapBuilder.cpp;rtps/messages/SendBuffersManager.cpp;rtps/messages/MessageReceiver.cpp;rtps/messages/submessages/AckNackMsg.hpp;rtps/messages/submessages/DataMsg.hpp;rtps/messages/submessages/GapMsg.hpp;rtps/messages/submessages/HeartbeatMsg.hpp;rtps/network/NetworkFactory.cpp;rtps/network/ReceiverResource.cpp;rtps/participant/RTPSParticipant.cpp;rtps/participant/RTPSParticipantImpl.cpp;rtps/RTPSDomain.cpp;fastrtps_deprecated/Domain.cpp;fastrtps_deprecated/participant/Participant.cpp;fastrtps_deprecated/participant/ParticipantImpl.cpp;fastrtps_deprecated/publisher/Publisher.cpp;fastrtps_deprecated/publisher/PublisherImpl.cpp;fastrtps_deprecated/publisher/PublisherHistory.cpp;fastrtps_deprecated/subscriber/Subscriber.cpp;fastrtps_deprecated/subscriber/SubscriberImpl.cpp;fastrtps_deprecated/subscriber/SubscriberHistory.cpp;fastdds/subscriber/DataReader.cpp;fastdds/publisher/DataWriter.cpp;fastdds/subscriber/DataReaderImpl.cpp;fastdds/publisher/DataWriterImpl.cpp;fastdds/topic/Topic.cpp;fastdds/topic/TopicImpl.cpp;fastdds/topic/TypeSupport.cpp;fastdds/topic/qos/TopicQos.cpp;fastdds/publisher/qos/DataWriterQos.cpp;fastdds/subscriber/qos/DataReaderQos.cpp;fastdds/topic/TypeSupport.cpp;fastdds/publisher/PublisherImpl.cpp;fastdds/publisher/qos/PublisherQos.cpp;fastdds/publisher/Publisher.cpp;fastdds/subscriber/SubscriberImpl.cpp;fastdds/subscriber/qos/SubscriberQos.cpp;fastdds/subscriber/Subscriber.cpp;fastdds/subscriber/DataReader.cpp;fastdds/subscriber/DataReaderImpl.cpp;fastdds/domain/DomainParticipantFactory.cpp;fastdds/domain/DomainParticipantImpl.cpp;fastdds/domain/DomainParticipant.cpp;fastdds/domain/qos/DomainParticipantQos.cpp;fastdds/domain/qos/DomainParticipantFactoryQos.cpp;fastdds/builtin/typelookup/common/TypeLookupTypes.cpp;fastdds/builtin/common/RPCHeadersImpl.cpp;fastdds/builtin/typelookup/TypeLookupManager.cpp;fastdds/builtin/typelookup/TypeLookupRequestListener.cpp;fastdds/builtin/typelookup/TypeLookupReplyListener.cpp;rtps/transport/ChannelResource.cpp;rtps/transport/UDPChannelResource.cpp;rtps/transport/TCPChannelResource.cpp;rtps/transport/TCPChannelResourceBasic.cpp;rtps/transport/TCPAcceptor.cpp;rtps/transport/TCPAcceptorBasic.cpp;rtps/transport/UDPv4Transport.cpp;rtps/transport/TCPTransportInterface.cpp;rtps/transport/UDPTransportInterface.cpp;rtps/transport/shared_mem/SharedMemTransportDescriptor.cpp;rtps/transport/TCPv4Transport.cpp;rtps/transport/UDPv6Transport.cpp;rtps/transport/TCPv6Transport.cpp;rtps/transport/test_UDPv4Transport.cpp;rtps/transport/tcp/TCPControlMessage.cpp;rtps/transport/tcp/RTCPMessageManager.cpp;dynamic-types/AnnotationDescriptor.cpp;dynamic-types/AnnotationParameterValue.cpp;dynamic-types/DynamicData.cpp;dynamic-types/DynamicDataFactory.cpp;dynamic-types/DynamicType.cpp;dynamic-types/DynamicPubSubType.cpp;dynamic-types/DynamicTypePtr.cpp;dynamic-types/DynamicDataPtr.cpp;dynamic-types/DynamicTypeBuilder.cpp;dynamic-types/DynamicTypeBuilderPtr.cpp;dynamic-types/DynamicTypeBuilderFactory.cpp;dynamic-types/DynamicTypeMember.cpp;dynamic-types/MemberDescriptor.cpp;dynamic-types/TypeDescriptor.cpp;dynamic-types/TypeIdentifier.cpp;dynamic-types/TypeIdentifierTypes.cpp;dynamic-types/TypeObject.cpp;dynamic-types/TypeObjectHashId.cpp;dynamic-types/TypeObjectFactory.cpp;dynamic-types/TypeNamesGenerator.cpp;dynamic-types/TypesBase.cpp;dynamic-types/BuiltinAnnotationsTypeObject.cpp;dynamic-types/DynamicDataHelper.cpp;fastrtps_deprecated/attributes/TopicAttributes.cpp;fastdds/core/policy/ParameterList.cpp;fastdds/publisher/qos/WriterQos.cpp;fastdds/subscriber/qos/ReaderQos.cpp;rtps/builtin/BuiltinProtocols.cpp;rtps/builtin/discovery/participant/DirectMessageSender.cpp;rtps/builtin/discovery/participant/PDP.cpp;rtps/builtin/discovery/participant/PDPSimple.cpp;rtps/builtin/discovery/participant/PDPListener.cpp;rtps/builtin/discovery/endpoint/EDP.cpp;rtps/builtin/discovery/endpoint/EDPSimple.cpp;rtps/builtin/discovery/endpoint/EDPSimpleListeners.cpp;rtps/builtin/discovery/endpoint/EDPStatic.cpp;rtps/builtin/liveliness/WLP.cpp;rtps/builtin/liveliness/WLPListener.cpp;rtps/builtin/data/ParticipantProxyData.cpp;rtps/builtin/data/WriterProxyData.cpp;rtps/builtin/data/ReaderProxyData.cpp;rtps/flowcontrol/ThroughputController.cpp;rtps/flowcontrol/ThroughputControllerDescriptor.cpp;rtps/flowcontrol/FlowController.cpp;rtps/exceptions/Exception.cpp;rtps/attributes/PropertyPolicy.cpp;rtps/common/Token.cpp;rtps/xmlparser/XMLParserCommon.cpp;rtps/xmlparser/XMLElementParser.cpp;rtps/xmlparser/XMLEndpointParser.cpp;rtps/xmlparser/XMLParser.cpp;rtps/xmlparser/XMLProfileManager.cpp;rtps/writer/PersistentWriter.cpp;rtps/writer/StatelessPersistentWriter.cpp;rtps/writer/StatefulPersistentWriter.cpp;rtps/reader/StatelessPersistentReader.cpp;rtps/reader/StatefulPersistentReader.cpp;rtps/persistence/PersistenceFactory.cpp;rtps/builtin/discovery/participant/timedevent/DSClientEvent.cpp;rtps/builtin/discovery/participant/timedevent/DServerEvent.cpp;rtps/builtin/discovery/participant/PDPClient.cpp;rtps/builtin/discovery/participant/PDPServer.cpp;rtps/builtin/discovery/participant/PDPServerListener.cpp;rtps/builtin/discovery/endpoint/EDPClient.cpp;rtps/builtin/discovery/endpoint/EDPServer.cpp;rtps/builtin/discovery/endpoint/EDPServerListeners.cpp;rtps/builtin/discovery/database/DiscoveryDataBase.cpp;rtps/builtin/discovery/database/DiscoveryParticipantsAckStatus.cpp;rtps/builtin/discovery/database/DiscoveryParticipantInfo.cpp;rtps/builtin/discovery/database/DiscoverySharedInfo.cpp;rtps/builtin/discovery/database/backup/SharedBackupFunctions.cpp;rtps/builtin/discovery/participant/DSClientEvent2.cpp;rtps/builtin/discovery/participant/DServerEvent2.cpp;rtps/builtin/discovery/participant/PDPClient2.cpp;rtps/builtin/discovery/participant/PDPServer2.cpp;rtps/builtin/discovery/participant/PDPServerListener2.cpp;rtps/builtin/discovery/endpoint/EDPClient2.cpp;rtps/builtin/discovery/endpoint/EDPServer2.cpp;rtps/builtin/discovery/endpoint/EDPServerListeners2.cpp;utils/IPFinder.cpp;utils/md5.cpp;utils/StringMatching.cpp;utils/IPLocator.cpp;utils/System.cpp;utils/TimedConditionVariable.cpp;dds/core/types.cpp;dds/core/Exception.cpp;dds/domain/DomainParticipant.cpp;dds/pub/Publisher.cpp;dds/pub/AnyDataWriter.cpp;dds/pub/DataWriter.cpp;dds/sub/Subscriber.cpp;dds/sub/DataReader.cpp;dds/topic/Topic.cpp;rtps/transport/shared_mem/test_SharedMemTransport.cpp;rtps/transport/shared_mem/SharedMemTransport.cpp;rtps/transport/TCPChannelResourceSecure.cpp;rtps/transport/TCPAcceptorSecure.cpp;SECTION;SECURITY;rtps/security/exceptions/SecurityException.cpp;rtps/security/common/SharedSecretHandle.cpp;rtps/security/logging/Logging.cpp;rtps/security/SecurityManager.cpp;rtps/security/SecurityPluginFactory.cpp;security/authentication/PKIDH.cpp;security/accesscontrol/Permissions.cpp;security/cryptography/AESGCMGMAC.cpp;security/cryptography/AESGCMGMAC_KeyExchange.cpp;security/cryptography/AESGCMGMAC_KeyFactory.cpp;security/cryptography/AESGCMGMAC_Transform.cpp;security/cryptography/AESGCMGMAC_Types.cpp;security/authentication/PKIIdentityHandle.cpp;security/authentication/PKIHandshakeHandle.cpp;security/accesscontrol/AccessPermissionsHandle.cpp;security/accesscontrol/CommonParser.cpp;security/accesscontrol/GovernanceParser.cpp;security/accesscontrol/PermissionsParser.cpp;security/logging/LogTopic.cpp;ENDSECTION;SECTION;SQLITE3;rtps/persistence/SQLite3PersistenceService.cpp;rtps/persistence/sqlite3.c;ENDSECTION;/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds/thirdparty/tinyxml2/tinyxml2.cpp)
    set(fastrtps_SOURCES_AUTOTOOLS "libfastrtps_la_SOURCES = ")
    set(section_ FALSE)
    set(restart_ FALSE)
    foreach(fastrtps_SOURCE ${fastrtps_SOURCES_TMP})
        if(section_)
            set(section_ FALSE)
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} \nif ${fastrtps_SOURCE}")
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} \nlibfastrtps_la_SOURCES += ")
        elseif(restart_)
            set(restart_ FALSE)
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} \nlibfastrtps_la_SOURCES += ")
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} ${fastrtps_SOURCE}")
        elseif("${fastrtps_SOURCE}" STREQUAL "SECTION")
            set(section_ TRUE)
            set(restart_ FALSE)
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} \n")
        elseif("${fastrtps_SOURCE}" STREQUAL "ENDSECTION")
            set(restart_ TRUE)
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} \nendif\n")
        else()
            set(fastrtps_SOURCES_AUTOTOOLS "${fastrtps_SOURCES_AUTOTOOLS} ${fastrtps_SOURCE}")
        endif()
    endforeach()
endmacro()

macro(generate_public_headers_for_autotools)
    set(fastrtps_PUBLIC_HEADERS_DIRECTORIES_TMP /home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds/include;/home/marlar/movelt/build/microxrcedds_agent/fastdds/src/fastdds/include)
    set(fastrtps_PUBLIC_HEADERS_AUTOTOOLS "")
    foreach(directory ${fastrtps_PUBLIC_HEADERS_DIRECTORIES_TMP})
        file(GLOB_RECURSE fastrtps_PUBLIC_HEADERS_TMP RELATIVE ${directory} ${directory}/*.h)
        foreach(fastrtps_PUBLIC_HEADER ${fastrtps_PUBLIC_HEADERS_TMP})
            set(fastrtps_PUBLIC_HEADERS_AUTOTOOLS "${fastrtps_PUBLIC_HEADERS_AUTOTOOLS} ${fastrtps_PUBLIC_HEADER}")
        endforeach()
        file(GLOB_RECURSE fastrtps_PUBLIC_HEADERS_TMP RELATIVE ${directory} ${directory}/*.hpp)
        foreach(fastrtps_PUBLIC_HEADER ${fastrtps_PUBLIC_HEADERS_TMP})
            set(fastrtps_PUBLIC_HEADERS_AUTOTOOLS "${fastrtps_PUBLIC_HEADERS_AUTOTOOLS} ${fastrtps_PUBLIC_HEADER}")
        endforeach()
    endforeach()

    set(fastrtps_PUBLIC_HEADERS_FILES_TMP fastrtps/config.h)
    foreach(file ${fastrtps_PUBLIC_HEADERS_FILES_TMP})
        set(fastrtps_PUBLIC_HEADERS_AUTOTOOLS "${fastrtps_PUBLIC_HEADERS_AUTOTOOLS} ${file}")
    endforeach()
endmacro()

