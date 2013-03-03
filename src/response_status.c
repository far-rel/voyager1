#include "response_status.h"

extern gint voy_response_status_from_string(gchar const * string_status) {

}

extern gchar *voy_repsonse_status_from_integer(gint integer_status) {
  switch (integer_status) {
      // 1** Informational statuses
    case 100:
      return VOY_CONTINUE;
    case 101:
      return VOY_SWITCHING_PROTOCOLS;
    case 102:
      return VOY_PROCESSING;
      // 2** Success statuses
    case 200:
      return VOY_OK;
    case 201:
      return VOY_CREATED;
    case 202:
      return VOY_ACCEPTED;
    case 203:
      return VOY_NON_AUTHORITATIVE_INFORMATION;
    case 204:
      return VOY_NO_CONTENT;
    case 205:
      return VOY_RESET_CONTENT;
    case 206:
      return VOY_PARTIAL_CONTENT;
    case 207:
      return VOY_MULTI_STATUS;
    case 208:
      return VOY_ALREADY_REPORTED;
    case 226:
      return VOY_IM_USED;
    case 250:
      return VOY_LOW_ON_STORAGE_SPACE;
      // 3** Redirection statuses
    case 300:
      return VOY_MULTIPLE_CHOICES;
    case 301:
      return VOY_MOVED_PERMANENTLY;
    case 302:
      return VOY_FOUND;
    case 303:
      return VOY_SEE_OTHER;
    case 304:
      return VOY_NOT_MODIFIED;
    case 305:
      return VOY_USE_PROXY;
    case 306:
      return VOY_SWITCH_PROXY;
    case 307:
      return VOY_TEMPORARY_REDIRECT;
    case 308:
      return VOY_PERMANENT_REDIRECT;
      // 4** Client errors statuses
    case 400:
      return VOY_BAD_REQUEST;
    case 401:
      return VOY_UNAUTHORIZED;
    case 402:
      return VOY_PAYMENT_REQUIRED;
    case 403:
      return VOY_FORBIDDEN;
    case 404:
      return VOY_NOT_FOUND;
    case 405:
      return VOY_METHOD_NOT_ALLOWED;
    case 406:
      return VOY_NOT_ACCEPTABLE;
    case 407:
      return VOY_PROXY_AUTHENTICATION_REQUIRED;
    case 408:
      return VOY_REQUEST_TIMEOUT;
    case 409:
      return VOY_CONFLICT;
    case 410:
      return VOY_GONE;
    case 411:
      return VOY_LENGTH_REQUIRED;
    case 412:
      return VOY_PRECONDITION_FAILED;
    case 413:
      return VOY_REQUEST_ENTITY_TOO_LARGE;
    case 414:
      return VOY_REQUEST_URI_TOO_LONG;
    case 415:
      return VOY_UNSUPPORTED_MEDIA_TYPE;
    case 416:
      return VOY_REQUESTED_RANGE_NOT_SATISFIABLE;
    case 417:
      return VOY_EXPECTATION_FAILED;
    case 418:
      return VOY_IM_A_TEAPOT;
    case 420:
      return VOY_ENHANCE_YOUR_CALM;
    case 422:
      return VOY_UNPROCESSABLE_ENTITY;
    case 423:
      return VOY_LOCKED;
    case 424:
      return VOY_FAILED_DEPENDENCY;
    case 425:
      return VOY_UNORDERED_COLLECTION;
    case 426:
      return VOY_UPGRADE_REQUIRED;
    case 428:
      return VOY_PRECONDITION_REQUIRED;
    case 429:
      return VOY_TOO_MENY_REQUESTS;
    case 431:
      return VOY_REQUSET_HEADER_FIELDS_TOO_LARGE;
    case 444:
      return VOY_NO_RESPONSE;
    case 449:
      return VOY_RETRY_WITH;
    case 450:
      return VOY_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS;
    case 451:
      return VOY_PARAMETER_NOT_UNDERSTOOD;
    case 452:
      return VOY_CONFERENCE_NOT_FOUND;
    case 453:
      return VOY_NOT_ENOUGH_BANDWIDTH;
    case 454:
      return VOY_SESSION_NOT_FOUND;
    case 455:
      return VOY_METHOD_NOT_VALID_IN_THIS_STATE;
    case 456:
      return VOY_HEADER_FIELD_NOT_VALID_FOR_RESOURCE;
    case 457:
      return VOY_INVALID_RANGE;
    case 458:
      return VOY_PARAMETER_IS_READ_ONLY;
    case 459:
      return VOY_AGGREGATE_OPERATION_NOT_ALLOWED;
    case 460:
      return VOY_ONLY_AGGREGATE_OPERATION_ALLOWED;
    case 461:
      return VOY_UNSUPPORTED_TRANSPORT;
    case 462:
      return VOY_DESTINATION_UNREACHABLE;
    case 494:
      return VOY_REQUEST_HEADER_TOO_LARGE;
    case 495:
      return VOY_CERT_ERROR;
    case 496:
      return VOY_NO_CERT;
    case 497:
      return VOY_HTTP_TO_HTTPS;
    case 499:
      return VOY_CLIENT_CLOSED_REQUEST;
      // 5** Server error statuses
    case 500:
      return VOY_INTERNAL_SERVER_ERROR;
    case 501:
      return VOY_NOT_IMPLEMENTED;
    case 502:
      return VOY_BAD_GATEWAY;
    case 503:
      return VOY_SERVICE_UNAVAILABLE;
    case 504:
      return VOY_GATEWAY_TIMEOUT;
    case 505:
      return VOY_HTTP_VERSION_NOT_SUPPORTED;
    case 506:
      return VOY_VARIANT_ALSO_NEGOTIATES;
    case 507:
      return VOY_INSUFFICIENT_STORAGE;
    case 508:
      return VOY_LOOP_DETECTED;
    case 509:
      return VOY_BANDWIDTH_LIMIT_EXCEEDED;
    case 510:
      return VOY_NOT_EXTENDED;
    case 511:
      return VOY_NETWORK_AUTHENTICATION_REQUIRED;
    case 551:
      return VOY_OPTION_NOT_SUPPORTED;
    case 598:
      return VOY_NETWORK_READ_TIMEOUT_ERROR;
    case 599:
      return VOY_NETWORK_CONNECT_TIMEOUT_ERROR;
  }
}